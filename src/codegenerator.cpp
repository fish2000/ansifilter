/***************************************************************************
                      codegenerator.cpp  -  description
                             -------------------
    copyright            : (C) 2007-2021 by Andre Simon
    email                : a.simon@mailbox.org
 ***************************************************************************/


/*
This file is part of ANSIFilter.

ANSIFilter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ANSIFilter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ANSIFilter.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "codegenerator.h"

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <cstdlib>
#include <cstring>
#include <fstream>
#include "version.h"

#include "pangogenerator.h"
#include "htmlgenerator.h"
#include "rtfgenerator.h"
#include "plaintextgenerator.h"
#include "texgenerator.h"
#include "latexgenerator.h"
#include "bbcodegenerator.h"
#include "svggenerator.h"

namespace ansifilter
{

CodeGenerator * CodeGenerator::getInstance(OutputType type)
{
    CodeGenerator* generator=NULL;
    switch (type) {
    case TEXT:
        generator = new PlaintextGenerator();
        break;
    case HTML:
        generator = new HtmlGenerator();
        break;
    case PANGO:
        generator = new PangoGenerator();
        break;
    case LATEX:
        generator = new LaTeXGenerator();
        break;
    case TEX:
        generator = new TeXGenerator();
        break;
    case RTF:
        generator = new RtfGenerator();
        break;
    case BBCODE:
        generator = new BBCodeGenerator();
        break;
    case SVG:
        generator = new SVGGenerator();
        break;

    default:
        break;
    }
    return generator;
}

CodeGenerator::CodeGenerator(ansifilter::OutputType type)
    :in(NULL),
     out(NULL),
     tagIsOpen(false),
     encoding("none"),
     docTitle("Source file"),
     fragmentOutput(false),
     font("Courier New"),
     fontSize("10pt"),

     lineNumberWidth ( 5 ),
     lineNumber ( 0 ),
     showLineNumbers ( false ),

     numberWrappedLines ( true ), //TODO add option
     numberCurrentLine(false),
     addAnchors(false),
     applyDynStyles(false),
     omitVersionInfo(false),
     parseCP437(false),
     parseAsciiBin(false),
     parseAsciiTundra(false),

     outputType(type),
     ignoreFormatting(false),
     readAfterEOF(false),
     omitTrailingCR(false),
     ignClearSeq(false),
     ignCSISeq(false),
     termBuffer(NULL),
     curX(0),
     curY(0),
     memX(0),
     memY(0),
     maxY(0),
     asciiArtWidth(80),
     asciiArtHeight(150),
     lineWrapLen(0)
{
    elementStyle.setFgColour(rgb2html(workingPalette[0]));
}

CodeGenerator::~CodeGenerator()
{}


void CodeGenerator::setShowLineNumbers(bool flag)
{
    showLineNumbers=flag;
}

void CodeGenerator::setFragmentCode(bool flag)
{
    fragmentOutput=flag;
}

void CodeGenerator::setWrapNoNumbers(bool flag)
{
    numberWrappedLines = flag;
}

void CodeGenerator::setParseCodePage437(bool flag){
    parseCP437 = flag;
}

void CodeGenerator::setParseAsciiBin(bool flag){
    parseAsciiBin = flag;
}

void CodeGenerator::setParseAsciiTundra(bool flag){
    parseAsciiTundra = flag;
}

void CodeGenerator::setIgnoreClearSeq(bool flag) {
    ignClearSeq = flag;
}

void CodeGenerator::setIgnoreCSISeq(bool flag) {
    ignCSISeq = flag;
}

void CodeGenerator::setAsciiArtSize(int width, int height){
    if (width>0) asciiArtWidth = width;
    if (height>0) asciiArtHeight = height;
}

bool CodeGenerator::getFragmentCode()
{
    return fragmentOutput;
}

void CodeGenerator::setFont(const string& s)
{
    font = s;
}

void CodeGenerator::setFontSize(const string& s)
{
    fontSize = s ;
}

void CodeGenerator::setTitle(const string & title)
{
    if (!title.empty())
        docTitle= title;
    std::size_t found = docTitle.rfind("/");
    if (found!=std::string::npos){
        docTitle = docTitle.substr(found+1);
    }
}

string CodeGenerator::getTitle()
{
    return docTitle;
}

void CodeGenerator::setEncoding(const string& encodingName)
{
    encoding = encodingName;
}

void CodeGenerator::setStyleSheet(const std::string& path)
{
    styleSheetPath=path;
}

void CodeGenerator::setPreformatting ( WrapMode lineWrappingStyle,
                                       unsigned int lineLength
                                     )
{

    lineWrapLen = lineLength;
}


void CodeGenerator::setApplyDynStyles(bool flag) {
    applyDynStyles = flag;
}

void CodeGenerator::setSVGSize ( const string& w, const string& h )
{
    width=w;
    height=h;
}

ParseError CodeGenerator::generateFile (const string &inFileName,
                                        const string &outFileName)
{

    ParseError error=PARSE_OK;

    in = (inFileName.empty()? &cin :new ifstream (inFileName.c_str() , std::ios::binary));


    if (!in->fail() && error==PARSE_OK) {
        out = (outFileName.empty()? &cout :new ofstream (outFileName.c_str()));
        if ( out->fail()) {
            error=BAD_OUTPUT;
        }
    }

    if ( in->fail()) {
        error=BAD_INPUT;
    }
    if (error==PARSE_OK) {
        if (! fragmentOutput) {
            *out << getHeader();
        }

        printBody();

        if (! fragmentOutput) {
            *out << getFooter();
        }
    }

    if (!outFileName.empty()) {
        delete out;
        out=NULL;
    }
    if (!inFileName.empty()) {
        delete in;
        in=NULL;
    }
    return error;
}

string CodeGenerator::generateString(const string &input)
{
    in = new istringstream (input);
    out = new ostringstream ();

    if ( in->fail() || out->fail()) {
        return "";
    }

    if (! fragmentOutput) {
        *out << getHeader();
    }

    printBody();

    if (! fragmentOutput) {
        *out << getFooter();
    }

    string result = static_cast<ostringstream*>(out)->str();

    delete out;
    out=NULL;
    delete in;
    in=NULL;

    return result;
}

string CodeGenerator::generateStringFromFile(const string &inFileName)
{

    in = new ifstream (inFileName.c_str() , std::ios::binary);
    out = new ostringstream ();

    if ( in->fail() || out->fail()) {
        return "";
    }

    if (! fragmentOutput) {
        *out << getHeader();
    }

    printBody();

    if (! fragmentOutput) {
        *out << getFooter();
    }

    string result = static_cast<ostringstream*>(out)->str();

    delete out;
    out=NULL;
    delete in;
    in=NULL;

    return result;
}

ParseError CodeGenerator::generateFileFromString (const string &sourceStr,
        const string &outFileName,
        const string &title)
{
    ParseError error=PARSE_OK;

    in = new istringstream (sourceStr);
    if (!in->fail()) {
        out = (outFileName.empty()? &cout :new ofstream (outFileName.c_str()));
        if ( out->fail()) {
            error=BAD_OUTPUT;
        }
    }

    if ( in->fail()) {
        error=BAD_INPUT;
    }

    if (error==PARSE_OK) {

        if (! fragmentOutput) {
            *out << getHeader();
        }

        printBody();

        if (! fragmentOutput) {
            *out << getFooter();
        }
    }

    if (!outFileName.empty()) {
        delete out;
        out=NULL;
    }

    delete in;
    in=NULL;

    return error;
}


bool CodeGenerator::printDynamicStyleFile ( const string &outPath )
{
    return true;
}

/*

 ESC[nL       Inserts n blank lines at cursor line.   (NANSI)
 ESC[nM       Deletes n lines including cursor line.  (NANSI)
 ESC[n@       Inserts n blank chars at cursor.        (NANSI)
 ESC[nP       Deletes n chars including cursor char.  (NANSI)
 ESC[n;ny     Output char translate                   (NANSI)
 */

bool CodeGenerator::parseSGRParameters(const string& line, size_t begin, size_t end)
{
    if (line.empty() || begin==end) { // fix empty grep --color ending sequence
      elementStyle.setReset(true);
      return true;
    }

    int ansiCode=0;
    int colorCode=0;
    unsigned char colorValues[3]= {0};

    string codes=line.substr(begin, end-begin);
    vector<string> codeVector = StringTools::splitString(codes, ';');

    vector<string>::iterator itVectorData = codeVector.begin();
    while( itVectorData != codeVector.end()) {
        StringTools::str2num<int>(ansiCode, *(itVectorData), std::dec);
        elementStyle.setReset(false);

        switch (ansiCode) {
        case 0:
            elementStyle.setReset(true);
            break;
        case 1:
            elementStyle.setBold(true);
            elementStyle.setFgColour(rgb2html(workingPalette[8]));
            break;
        case 2: //Faint
            break;

        case 3:
            elementStyle.setItalic(true);
            break;

        case 5: //Blink
        case 6: //Blink fast
            elementStyle.setBlink(true);
            break;

        case 7:
            elementStyle.imageMode(true);
            break;

        case 8:
            elementStyle.setConceal(true);
            break;

        case 4:// Underline Single
        case 21: // Underline double
            elementStyle.setUnderline(true);
            break;

        case 22:
            elementStyle.setBold(false);
            break;

        case 24:
            elementStyle.setUnderline(false);
            break;

        case 25:
            elementStyle.setBlink(false);
            break;

        case 27:
            elementStyle.imageMode(false);
            break;

        case 28:
            elementStyle.setConceal(false);
            break;

        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
            if (elementStyle.isBold()){
              elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-30+8]));
            } else
              elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-30]));
            break;

        case 38: // xterm 256 foreground color mode \033[38;5;<color>

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            if (*(itVectorData)=="5") {
                itVectorData++;
                if (itVectorData == codeVector.end()) break;

                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                xterm2rgb((unsigned char)colorCode, colorValues);
                elementStyle.setFgColour(rgb2html(colorValues));
            } else if (*(itVectorData)=="2") {

                itVectorData++;
                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[0] = colorCode & 0xff;
                itVectorData++;

                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[1] = colorCode & 0xff;

                itVectorData++;
                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[2] = colorCode & 0xff;

                elementStyle.setFgColour(rgb2html(colorValues));
            }
            break;

        case 39:
          elementStyle.setReset(true);
            break;

        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
            elementStyle.setBgColour(rgb2html(workingPalette[ansiCode-40]));
            break;

        case 48:  // xterm 256 background color mode \033[48;5;<color>

            itVectorData++;
            if (itVectorData == codeVector.end()) break;

            if(*(itVectorData)=="5") {

                itVectorData++;
                if (itVectorData == codeVector.end()) break;

                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                xterm2rgb((unsigned char)colorCode, colorValues);
                elementStyle.setBgColour(rgb2html(colorValues));
            } else if (*(itVectorData)=="2") {

                itVectorData++;
                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[0] = colorCode & 0xff;
                itVectorData++;

                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[1] = colorCode & 0xff;

                itVectorData++;
                if (itVectorData == codeVector.end()) break;
                StringTools::str2num<int>(colorCode, *(itVectorData), std::dec);
                colorValues[2] = colorCode & 0xff;

                elementStyle.setBgColour(rgb2html(colorValues));
            }

            break;

        case 49:
          elementStyle.setReset(true);
            break;

        /*aixterm codes*/
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
            elementStyle.setFgColour(rgb2html(workingPalette[ansiCode-90+8]));
            break;

        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
            elementStyle.setBgColour(rgb2html(workingPalette[ansiCode-100+8]));
            break;
        }

        // Set RTF color index
        // 8 default colours followed by bright colors see rtfgenerator.cpp
        if (ansiCode>=30 and ansiCode <=37)
          elementStyle.setFgColourID(ansiCode-30 + (elementStyle.isBold()? 8 : 0) );
        else if (ansiCode>=90 and ansiCode <98)
          elementStyle.setFgColourID(ansiCode-90+8);

        else if (ansiCode>=40 and ansiCode <=47)
          elementStyle.setBgColourID(ansiCode-40 /*+ elementStyle.isBold()? 8 : 0 */);
        else if (ansiCode>=100 and ansiCode <108)
          elementStyle.setBgColourID(ansiCode-100+8);

        if (itVectorData != codeVector.end()) itVectorData++;
    }

    return true;
}


void CodeGenerator::parseCodePage437Seq(string line, size_t begin, size_t end){

  string codes=line.substr(begin, end-begin);
  vector<string> codeVector = StringTools::splitString(codes, ',');

  if (line[end]=='H'){
    codeVector = StringTools::splitString(codes, ';');

    curX = curY = 0;
    if (codeVector.size()==1) {
      curY = atoi(codeVector[0].c_str());
    } else  if (codeVector.size()==2){
     curY = atoi(codeVector[0].c_str());
     curX = atoi(codeVector[1].c_str());
    }

    if (maxY<curY && curY<asciiArtHeight) maxY=curY;
  }

  if (line[end]=='A'){
    if (codeVector.size()==1){
      curY -= atoi(codeVector[0].c_str());
     } else {
      curY--;
    }
  }

  if (line[end]=='B'){
    if (codeVector.size()==1){
      curY += atoi(codeVector[0].c_str());
    } else {
      curY++;
    }
    if (maxY<curY && curY<asciiArtHeight) maxY=curY;
  }

  if (line[end]=='C'){

    if (codeVector.size()==1){
      curX += atoi(codeVector[0].c_str());
    } else {
      curX++;
    }

    //handle coloumn overflow
    if (curX>asciiArtWidth && curY<asciiArtHeight){
      curX-=asciiArtWidth;
      curY++;
      if (maxY<curY && curY<asciiArtHeight) maxY=curY;
    }
  }

  if (line[end]=='D'){
    if (codeVector.size()==1){
      curX -= atoi(codeVector[0].c_str());
     } else {
      curX--;
    }
    if (curX<0) curX=0;
  }

  if (line[end]=='J'){
 //   std::cerr<<"J!!!\n";
    /*
    if (codeVector.size()==1 && codeVector[0]=="2"){
      for (int i=0;i<100*100;i++) *termBuffer[i]->c =0;
    }
    */
  }

  if (line[end]=='K'){
  //  std::cerr<<"K!!!\n";
    //    for (int i=curX;i<asciiArtWidth;i++) termBuffer[curY*asciiArtWidth + i]->c =0;

  }

  if (line[end]=='s'){
    memX = curX;
    memY = curY;
    memStyle = elementStyle;
  }
  if (line[end]=='u'){
    curX = memX;
    curY = memY;
    elementStyle=memStyle;
  }

}

void CodeGenerator::insertLineNumber ()
{
    if ( showLineNumbers && !parseCP437) {

        ostringstream lnum;
        lnum << setw ( 5 ) << right;
        if( numberCurrentLine ) {
            *out << getCloseTag();
            lnum << lineNumber;
            *out <<lnum.str()<<spacer;
            *out << getOpenTag();
        } else {
            *out << lnum.str(); //for indentation
        }
    }
}

void CodeGenerator::printTermBuffer() {

    for (int y=0;y<=maxY;y++) {

        for (int x=0;x<asciiArtWidth;x++) {
            if (termBuffer[x + y* asciiArtWidth].c=='\r') {
                break;
            }
            elementStyle = termBuffer[x + y* asciiArtWidth].style;

            //full block
            if (termBuffer[x + y* asciiArtWidth].c == 0xdb){
                elementStyle.setBgColour(elementStyle.getFgColour());
            }

            if (!elementStyle.isReset()) {
                *out <<getOpenTag();
            }

            *out << maskCP437Character(termBuffer[x + y* asciiArtWidth].c);

            if (!elementStyle.isReset()) {
                *out <<getCloseTag();
            }
        }
    *out<<newLineTag;
  }
  out->flush();
  delete [] termBuffer;
}


void CodeGenerator::parseBinFile(){
  char buffer [2] = {0};
  int cur=0;
  int next=0;
  int count=0;
  allocateTermBuffer();
  while (in->read (buffer, 2)){

    cur = buffer[0]&0xff;
    next = buffer[1]&0xff;

    int colBg = (next & 240) >> 4;
    int colFg = (next & 15);

    if (colBg > 8)
    {
      colBg -= 8;
    }

    elementStyle.setFgColour(rgb2html(workingPalette[colFg]));
    elementStyle.setBgColour(rgb2html(workingPalette[colBg]));

    //FIXME:
    elementStyle.setBold(cur >= 0x20 && cur <= 0x7a);

    if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
      termBuffer[curX + curY*asciiArtWidth].c = cur;
      termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
      curX++;
    }
    if (count % asciiArtWidth == 0 ) {
      curY++;
      if (maxY<curY && curY<asciiArtHeight) maxY=curY;
      curX=0;
    }
    count+=2;
  }
}

// the XBIN decoding function is based on AnsiLove:
// https://github.com/ansilove/
void CodeGenerator::parseXBinFile(){

    char header [11] = {0};
    char palette [48] = {0};

    if (in->read(header, 11)){

      asciiArtWidth = 0xff & ((header[ 6 ] << 8) + header[ 5 ]);
      asciiArtHeight = 0xff & ((header[ 8 ] << 8) + header[ 7 ]);
      int fontSize = header[ 9 ];
      int flags = header[ 10 ];
/*
      std::cerr<<"XBIN width:"<<asciiArtWidth<<"\n";
      std::cerr<<"XBIN height:"<<asciiArtHeight<<"\n";
      std::cerr<<"XBIN fontsize:"<<fontSize<<"\n";
      std::cerr<<"XBIN flags:"<<flags<<"\n";
*/
      allocateTermBuffer();

      if( (flags & 1) == 1 && in->read(palette, 48)) {
        int loop;
        int index;

        //override default palette
        //TODO allow user to override this with a map?
        for (loop = 0; loop < 16; loop++)
        {
          index = loop * 3;
          workingPalette[loop][0] = palette[index] << 2 | palette[index] >> 4;
          workingPalette[loop][1] = palette[index+1] << 2 | palette[index+1] >> 4;
          workingPalette[loop][2] = palette[index+2] << 2 | palette[index+2] >> 4;
        }
      }

      // skip font
      if( (flags & 2) == 2 ) {
        int numchars = ( flags & 0x10 ? 512 : 256 );
        in->seekg ( fontSize * numchars, ios::cur);
      }

      // decode image
      if( (flags & 4) == 4) {
        int c=0;
        while( in && curY < asciiArtHeight)
        {
          c = in->get();
          int compression = c & 0xC0;
          int cnt = ( c & 0x3F ) + 1;

          int cur = -1;
          int attr = -1;

          while( cnt-- ) {
            // none
            if( compression == 0 ) {
              cur = in->get();
              attr = in->get();
            }
            // char
            else if ( compression == 0x40 ) {
              if( cur == -1 ) {
                cur = in->get();
              }
              attr = in->get();
            }
            // attr
            else if ( compression == 0x80 ) {
              if( attr == -1 ) {
                attr = in->get();
              }
              cur = in->get();
            }
            // both
            else {
              if( cur == -1 ) {
                cur = in->get();
              }
              if( attr == -1 ) {
                attr = in->get();
              }
            }

            int colBg = (attr & 240) >> 4;
            int colFg = (attr & 15);

            if (colBg > 8)
            {
              colBg -= 8;
            }

            elementStyle.setFgColour(rgb2html(workingPalette[colFg]));
            elementStyle.setBgColour(rgb2html(workingPalette[colBg]));

            //FIXME:
            elementStyle.setBold(cur >= 0x20 && cur <= 0x7a);

            if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
              termBuffer[curX + curY*asciiArtWidth].c = cur;
              termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
              curX++;
            }

            if (curX == asciiArtWidth)
            {
              curX = 0;
              curY++;
              if (maxY<curY && curY<asciiArtHeight) maxY=curY;
            }
          }
        }
    } else {
      //flat BIN
      parseBinFile();
    }
  }
}

// the TND decoding function is based on AnsiLove:
// https://github.com/ansilove/
void CodeGenerator::parseTundraFile(){
    char buffer  [10] = {0};
    bool isTundra = false;
    if ( in->read (buffer, 9) ) {
        isTundra = string(buffer)=="\x18TUNDRA24";
    }

    if (!isTundra) {
        std::cerr<<"not a Tundra file\n";
        return;
    }

    asciiArtWidth = 80;

    allocateTermBuffer();

    int fg_red=0, fg_green=0, fg_blue=0;
    int bg_red=0, bg_green=0, bg_blue=0;
    while (in->read (buffer, 1)){

        if (curX >= asciiArtWidth){
            curX = 0;
            curY ++;
        }

        int cur = buffer[0]&0xff;

        if (cur==1) {
            if (!in->read (buffer, 8)) goto GENTLE_EXIT;

            curY = ((buffer[0] << 24)& 0xff) + ((buffer[1] << 16)& 0xff) + ((buffer[2] << 8)& 0xff) + (buffer[3]& 0xff);
            curX = ((buffer[4] << 24)& 0xff) + ((buffer[5] << 16)& 0xff) + ((buffer[6] << 8)& 0xff) + (buffer[7]& 0xff);
        }

        if (cur == 2)
        {
            if (!in->read (buffer, 5) ) goto GENTLE_EXIT;

            fg_red=buffer[2];
            fg_green=buffer[3];
            fg_blue=buffer[4];
            cur= buffer[0];
        }

        if (cur == 4)
        {
            if (!in->read (buffer, 5) ) goto GENTLE_EXIT;
            bg_red=buffer[2];
            bg_green=buffer[3];
            bg_blue=buffer[4];
            cur= buffer[0];
        }

        if (cur==6)
        {
            if (!in->read (buffer, 10) ) goto GENTLE_EXIT;

            fg_red=buffer[2];
            fg_green=buffer[3];
            fg_blue=buffer[4];

            bg_red=buffer[6];
            bg_green=buffer[7];
            bg_blue=buffer[8];

            cur = buffer[0];
        }

        if (cur !=1 && cur !=2 && cur !=4 && cur !=6)
        {
            elementStyle.setFgColour(rgb2html( fg_red&0xff, fg_green&0xff, fg_blue&0xff));
            elementStyle.setBgColour(rgb2html( bg_red&0xff, bg_green&0xff, bg_blue&0xff ));

            termBuffer[curX + curY*asciiArtWidth].style = elementStyle;

            termBuffer[curX + curY*asciiArtWidth].c  = cur &0xff;
            curX++;
        }
  }

GENTLE_EXIT:

  maxY =  curY<asciiArtHeight ?  curY : asciiArtHeight;
}

void CodeGenerator::allocateTermBuffer(){

  if (termBuffer) delete [] termBuffer;

  termBuffer = new TDChar[asciiArtWidth*asciiArtHeight];
  for (int i=0; i<asciiArtWidth*asciiArtHeight; i++){
    termBuffer[i].c=0;
  }
}

bool CodeGenerator::streamIsXBIN() {
  if (in==&cin) return false;

  bool isXBIN = false;
  char head[5] = {0};
  if (in->read (head, sizeof head -1) ) {
    isXBIN = string(head)=="XBIN";
  }
  in->clear();
  in->seekg (0, ios::beg);
  return isXBIN;
}


bool CodeGenerator::streamIsTundra() {
  if (in==&cin) return false;

  bool isTND = false;
  char head[10] = {0};

  if (in->read (head, sizeof head -1) ) {
    isTND = string(head)=="\x18TUNDRA24";
  }
  in->clear();
  in->seekg (0, ios::beg);
  return isTND;
}
////////////////////////////////////////////////////////////////////////////

void CodeGenerator::processInput()
{
  int cur=0;
  int next=0;

  if (parseCP437 || parseAsciiBin || parseAsciiTundra){
    elementStyle.setReset(false);
  }

  // deal with BIN/XBIN without file watching, reformatting and line numbering distractions
  if (parseAsciiBin){

    if (streamIsXBIN())
      parseXBinFile();
    else
      parseBinFile();

    printTermBuffer();
    return;
  }

  if (parseAsciiTundra && streamIsTundra()){
    parseTundraFile();

    printTermBuffer();
    return;
  }


  // handle normal text files
  if (readAfterEOF && in!=&cin) {
    in->seekg (0, ios::end);
    // output the last few lines or the complete file if not too big
    if (in->tellg()>51200) {
      in->seekg (-512, ios::end);
      // output complete lines, ignore cur line fragment
      in->ignore(512, '\n');
    } else {
      in->seekg (0, ios::beg); // output complete file
    }
  }

  if (streamIsXBIN()) {
   *out<<"Please apply --art-bin option for XBIN files.\n";
   return;
  }

  if (streamIsTundra()) {
   *out<<"Please apply --art-tundra option for TND files.\n";
   return;
  }

  string line;
  size_t i=0;
  size_t plainTxtCnt=0;
  bool tagOpen=false;
  bool isGrepOutput=false;
  bool isKSeq=false;

  bool omitNewLine=false;
  lineNumber=0;

  if (parseCP437){
    allocateTermBuffer();
  }

  while (true) {

    bool eof=false;

    eof=!getline(*in, line);

    if( !omitNewLine )
        ++lineNumber;

    numberCurrentLine = true;

    if (eof) {
      // imitate tail bahaviour, continue to read after EOF
      if (readAfterEOF) {
        out->flush();
        in->clear();
        #ifdef WIN32
        Sleep(250);
        #else
        sleep(1);
        #endif
      } else {
        if (!parseCP437 && !omitTrailingCR)
            printNewLine(outputType!=TEXT);
        break;
      }
    } else {

      if (!omitNewLine && !parseCP437 && lineNumber>1)
          printNewLine();

      if (!omitNewLine )
          insertLineNumber();

      omitNewLine = false;

      i=0;
      plainTxtCnt=0;
      size_t seqEnd=string::npos;

      while (i <line.length() ) {
        // CSI ?
        cur = line[i]&0xff;

        if (parseCP437){

          if (cur==0x1b && line.length() - i > 2){
            next = line[i+1]&0xff;
            if (next==0x5b) {
              i+=2;
              seqEnd = i;
              //find sequence end
              while (   seqEnd<line.length()
                && (line[seqEnd]<0x40 || line[seqEnd]>0x7e )) {
                ++seqEnd;
                }

                if ( line[seqEnd]=='m' ) {
                  parseSGRParameters(line, i, seqEnd);
                } else {
                  parseCodePage437Seq(line, i, seqEnd);
                }
                i=seqEnd+1;
            }
            else {
                ++i;
            }
          } else  if (cur==0x1a && line.length() - i > 6){
            // skip SAUCE info section
            while (line[i]==0x1a || !line[i]) ++i;
            if (line.substr(i, 5)=="SAUCE"){
              break;
            }
          } else {
            if (curX>=0 && curX<asciiArtWidth && curY>=0 && curY<asciiArtHeight){
              termBuffer[curX + curY*asciiArtWidth].c = line[i];
              termBuffer[curX + curY*asciiArtWidth].style = elementStyle;
              curX++;
            }

            if (curX==asciiArtWidth || line[i]=='\r' ) {
              curY++;
              if (maxY<curY && curY<asciiArtHeight) maxY=curY;
              curX=0;
              if (line[i]=='\r') i=line.length();
            }
            ++i;
          }
        } else {

          if ( (cur&0xff)==0x0d && i<line.length()-1) {
            plainTxtCnt-=i;

            lineBuf.seekp(showLineNumbers ? 0 : 0, ios::beg);
            lineBuf<<getOpenTag();
          }
            // wrap line
          if (lineWrapLen && plainTxtCnt && plainTxtCnt % lineWrapLen==0) {
              ++lineNumber;
              printNewLine();
              insertLineNumber();
              plainTxtCnt=0;
           }

          if ( line.length() - i > 2 && (line[i+1]&0xff)==0x08) i++;
          if ( cur==0x07) {
              ++lineNumber;
              printNewLine();
              insertLineNumber();
        }

          if ( cur==0x1b || (!ignCSISeq && ( cur==0x9b || cur==0xc2)) ) {

            if (line.length() - i > 2){
              next = line[i+1]&0xff;

              //move index behind CSI
              if ( (cur==0x1b && next==0x5b) || ( cur==0xc2 && next==0x9b) ) {
                  ++i;
              } else {
                  // restore a unicode sequence if the two digit CSI is not matched
                  // ansiweather -l Berlin,DE | ansifilter -T
                  if (cur==0xc2 || cur==0x1b) {
                      lineBuf << maskCharacter(cur);
                      ++plainTxtCnt;
                }

              }

              // http://linuxcommand.org/lc3_adv_tput.php
              // http://ascii-table.com/ansi-escape-sequences-vt-100.php
              if (next==0x28){ // ( -> maybe need to handle more codes here
                  if (line[i+2]==0x42) { // B
                      elementStyle.setReset(false);
                      i+=2;
                }
              }

            // https://iterm2.com/documentation-escape-codes.html
            if (next==0x5d) {

                if (line[i+2]=='8') {

                    size_t uriBegin = line.find(';', i+4);
                    seqEnd = line.find("\x1b]8;;\x07", i);
                    size_t uriDelim = line.find(0x07, uriBegin+1);

                    if (uriBegin != string::npos && seqEnd != string::npos){
                        string uri = line.substr(uriBegin+1, uriDelim - uriBegin - 1 );
                        string txt = line.substr(uriDelim+1, seqEnd - uriDelim - 1);
                        lineBuf << getHyperlink(uri, txt);
                        i=seqEnd+4;
                    }
                }
                ++i;
            }

              if (i<line.size()) ++i;

              if (line[i-1]==0x5b || (line[i-1]&0xff)==0x9b){
                seqEnd=i;
                //find sequence end
                while (   seqEnd<line.length()
                  && (line[seqEnd]<0x40 || line[seqEnd]>0x7e )) {
                    ++seqEnd;
                  }

                  if (   line[seqEnd]=='m' && !ignoreFormatting ) {
                    if (!elementStyle.isReset()) {
                      lineBuf << getCloseTag();
                      tagOpen=false;
                    }
                    parseSGRParameters(line, i, seqEnd);
                    if (!elementStyle.isReset()) {
                      lineBuf << getOpenTag();
                      tagOpen=true;
                    }
                  }

                  // fix K sequences (iterm2/grep)
                  isKSeq =  line[seqEnd]=='K' && !ignClearSeq ;
                  isGrepOutput = isKSeq && isascii(line[seqEnd+1]) && line[seqEnd+1] !=13 && line[seqEnd+1] != 27;

                  if (   line[seqEnd]=='s' || line[seqEnd]=='u'
                    || (isKSeq && !isGrepOutput) ){
                      i=line.length()+1;
                      omitNewLine = isKSeq; // \n may follow K
                      //FIXME std::cerr << "K CASE!\n";
                  }
                  else {
                      i = 1 + ((seqEnd!=line.length())?seqEnd:i);
                  }
              } else {
                cur= line[i-1]&0xff;
                next = line[i]&0xff;

                //ignore content of two and single byte sequences (no CSI)
                if (cur==0x1b && (  next==0x50 || next==0x5d || next==0x58
                  || next==0x5e||next==0x5f ) ) // DECSC seq
                {
                  seqEnd=i;
                  //find string end
                  while ( seqEnd<line.length()
                      && (line[seqEnd]&0xff)!=0x9e
                      && line[seqEnd]!=0x07
                      && (line[seqEnd]&0xff)!=0x3b ) {
                        ++seqEnd;
                    }

                    if (line[seqEnd+1]=='A')
                        seqEnd++;

                    i=seqEnd+1;
                } else if (cur==0x1b && (
                   next==0x37 || next==0x38

                ) ) // DECSC seq
                {
                    if (line[seqEnd+1]==0x1b)
                        ++i;
                }
              }
            } else {
                ++i;
            }
          } else if (!ignCSISeq && (cur==0x90 || cur==0x9d || cur==0x98 || cur==0x9e ||cur==0x9f)) {
            seqEnd=i;
            //find string end
            while (   seqEnd<line.length() && (line[seqEnd]&0xff)!=0x9e
              && line[seqEnd]!=0x07 ) {
              ++seqEnd;
              }
              // handle false positives in unicode sequences
              // TODO fix set terminal title CSI (testansi.py)
              if (seqEnd<line.length() ) {
                  i=seqEnd+1;
              } else {
                lineBuf << maskCharacter(line[i]);
                ++i;
                ++plainTxtCnt;
              }
          } else {
            // output printable character
            lineBuf << maskCharacter(line[i]);
            ++i;
            ++plainTxtCnt;
          }
        }
      }
    }
  } // while (true)

  if (tagOpen) {
    *out <<getCloseTag();
  }

  if (parseCP437){
    printTermBuffer();
  }
  out->flush();
}


void CodeGenerator::printNewLine(bool eof) {

    string lineStr(lineBuf.str());
    if (eof) {
        lineStr = lineStr.substr(0, lineBuf.tellp());
    }
    *out << lineStr;
    *out << newLineTag;

    lineBuf.clear();
    lineBuf.str(std::string());
}


/* the following functions are based on Wolfgang Frischs xterm256 converter utility:
   http://frexx.de/xterm-256-notes/
*/
void CodeGenerator::xterm2rgb(unsigned char color, unsigned char* rgb)
{
    // 16 basic colors
    if(color<16) {
        rgb[0] = workingPalette[color][0];
        rgb[1] = workingPalette[color][1];
        rgb[2] = workingPalette[color][2];
    }

    // color cube color
    if(color>=16 && color<=232) {
        color-=16;
        rgb[0] = valuerange[(color/36)%6];
        rgb[1] = valuerange[(color/6)%6];
        rgb[2] = valuerange[color%6];
    }

    // gray tone
    if(color>232) {
        rgb[0]=rgb[1]=rgb[2] = 8+(color-232)*0x0a;
    }
}

string CodeGenerator::rgb2html(unsigned char* rgb){
  char colorString[10]= {0};
  sprintf(colorString, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
  return string(colorString);
}

string CodeGenerator::rgb2html(int r, int g, int b){
  char colorString[10]= {0};
  sprintf(colorString, "#%02x%02x%02x", r, g, b);
  return string(colorString);
}

const unsigned char CodeGenerator::valuerange[] = { 0x00, 0x5F, 0x87, 0xAF, 0xD7, 0xFF };

unsigned char CodeGenerator::defaultPalette[16][3] = {
    { 0x00, 0x00, 0x00 }, // 0 ColorBlack
    { 0xCD, 0x00, 0x00 }, // 1 ColorRed
    { 0x00, 0xCD, 0x00 }, // 2 ColorGreen
    { 0xCD, 0xCD, 0x00 }, // 3 ColorYellow
    { 0x00, 0x00, 0xEE }, // 4 ColorBlue
    { 0xCD, 0x00, 0xCD }, // 5 ColorMagenta
    { 0x00, 0xCD, 0xCD }, // 6 ColorCyan
    { 0xE5, 0xE5, 0xE5 }, // 7 ColorGray
    { 0x7F, 0x7F, 0x7F }, // 8 ColorDarkGray
    { 0xFF, 0x00, 0x00 }, // 9 ColorBrightRed
    { 0x00, 0xFF, 0x00 }, // 10 ColorBrightGreen
    { 0xFF, 0xFF, 0x00 }, // 11 ColorBrightYellow
    { 0x5C, 0x5C, 0xFF }, // 12 ColorBrightBlue
    { 0xFF, 0x00, 0xFF }, // 13 ColorBrightMagenta
    { 0x00, 0xFF, 0xFF }, // 14 ColorBrightCyan
    { 0xFF, 0xFF, 0xFF }  // 15 ColorBrightWhite
};

unsigned char CodeGenerator::workingPalette[16][3] = {
    { 0x00, 0x00, 0x00 }, // 0 ColorBlack
    { 0xCD, 0x00, 0x00 }, // 1 ColorRed
    { 0x00, 0xCD, 0x00 }, // 2 ColorGreen
    { 0xCD, 0xCD, 0x00 }, // 3 ColorYellow
    { 0x00, 0x00, 0xEE }, // 4 ColorBlue
    { 0xCD, 0x00, 0xCD }, // 5 ColorMagenta
    { 0x00, 0xCD, 0xCD }, // 6 ColorCyan
    { 0xE5, 0xE5, 0xE5 }, // 7 ColorGray
    { 0x7F, 0x7F, 0x7F }, // 8 ColorDarkGray
    { 0xFF, 0x00, 0x00 }, // 9 ColorBrightRed
    { 0x00, 0xFF, 0x00 }, // 10 ColorBrightGreen
    { 0xFF, 0xFF, 0x00 }, // 11 ColorBrightYellow
    { 0x5C, 0x5C, 0xFF }, // 12 ColorBrightBlue
    { 0xFF, 0x00, 0xFF }, // 13 ColorBrightMagenta
    { 0x00, 0xFF, 0xFF }, // 14 ColorBrightCyan
    { 0xFF, 0xFF, 0xFF }  // 15 ColorBrightWhite
};

bool CodeGenerator::setColorMap(const string& mapPath){

  //restore default colors
  if (mapPath.length()==0){
   memcpy(workingPalette, defaultPalette, sizeof defaultPalette);
   return true;
  }

  ifstream mapFile ( mapPath.c_str() );
  if ( mapFile ) {

      string line;

      unsigned int idx=0;
      char sep='\0';

      string colorCode;
      while ( getline ( mapFile, line ) ) {
        stringstream s(line);

        s>>idx;
        if (idx>15) return false;

        s>>sep;
        if (sep!='=') return false;

        s>>colorCode;
        if (colorCode.size()>=7 && colorCode[0]=='#' ) {
          workingPalette[idx][0] = (char)std::strtol(colorCode.substr ( 1, 2 ).c_str(), NULL, 16);
          workingPalette[idx][1] = (char)std::strtol(colorCode.substr ( 3, 2 ).c_str(), NULL, 16);
          workingPalette[idx][2] = (char)std::strtol(colorCode.substr ( 5, 2 ).c_str(), NULL, 16);
        } else {
          return false;
        }
      }
      mapFile.close();
  } else {
      return false;
  }
  return true;
}

}
