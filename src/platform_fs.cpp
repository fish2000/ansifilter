/***************************************************************************
                          platform_fs.cpp  -  description
                             -------------------
    begin                : Sun Oct 13 2007
    copyright            : (C) 2007-2020 by Andre Simon
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

#include "platform_fs.h"

#include <sys/stat.h>

using namespace std;

namespace Platform {

#ifdef _WIN32
    const char pathSeparator = '\\';
#else
    const char pathSeparator = '/';
#endif

//-D_FILE_OFFSET_BITS=64
//268435456 256 MB

off_t fileSize(const string& fName) {
    struct stat fileInfo;
    if(stat(fName.c_str(), &fileInfo) != 0) {
        return 0;
    }
    return fileInfo.st_size;   
}

}

