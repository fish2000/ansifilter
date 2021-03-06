#!/usr/bin/python
#-*- coding: utf-8 -*-

print ( "\033[0mAll attributes off\033[0m\n")
print ( "\033[1;4mBold\nBold\nBold\033[0m\n")
print ( "\033[4mUnderline\033[0m\n")
print ( "\033[3mItalic\033[0m\n")
print ( "\033[5mBlink\033[0m\n")
print ( "\033[8mHide\033[0m\n")
print ( "\033[30mBlack\033[0m\n")
print ( "\033[31mRed\nRed\nRed\nRed\033[0m\n")
print ( "\033[32mGreen\033[0m\n")
print ( "\033[33mYellow\033[0m\n")
print ( "\033[34mBlue\033[0m\n")
print ( "\033[35mMagenta\033[0m\n")
print ( "\033[36mCyan\033[0m\n")
print ( "\033[37mWhite\033[0m\n")

print ( "\033[90mDarkGray Bright\033[0m\n")
print ( "\033[91mRed Bright\033[0m\n")
print ( "\033[92mGreen Bright\033[0m\n")
print ( "\033[93mYellow Bright\033[0m\n")
print ( "\033[94mBlue Bright\033[0m\n")
print ( "\033[95mMagenta Bright\033[0m\n")
print ( "\033[96mCyan Bright\033[0m\n")
print ( "\033[97mWhite Bright\033[0m\n")

print ( "\033[38mTEST\033[0m\n")
print ( "\033[39mTEST\033[0m\n")
print ( "\033[40m\033[37mBlack Background\033[0m\n")
print ( "\033[41mRed Background\033[0m\n")
print ( "\033[101mRed Background Bright\033[0m\n")
print ( "\033[42mGreen Background\033[0m\n")
print ( "\033[43mYellow Background\033[0m\n")
print ( "\033[44mBlue Background\033[0m\n")
print ( "\033[45mMagenta Background\033[0m\n")
print ( "\033[46mCyan Background\033[0m\n")
print ( "\033[47mWhite Background\033[0m\n")
print ( "\033[48mTEST\033[0m\n")
print ( "\033[49mTEST\033[0m\n")

print ( "\033[48;5;1;128mTEST 256 Colours\033[0m\n")
print ( "\033[48;28;129mTEST 256 Colours\033[0m\n")
print ( "\033[48;7;132mTEST 256 Colours\033[0m\n")
print ( "\033[48;131mTEST 256 Colours\033[0m\n")
print ( "\033[48;130mTEST 256 Colours\033[0m\n")
print ( "\033[48;32;47mTEST 256 Colours\033[0m\n")

#alternative CSI
print ( "CSI\23332mGreen ALT CSI\2330mDefault\n")
print ( "CSI\23333mYellow ALT CSI\2330mDefault\n")
print ( "CSI\xc2\x9b33mYellow UTF8 CSI\xc2\x9b0mDefault\n")

# xterm sequences)
#^[]0;~^G^M^M)
print ( "Delete:\033]0;~\007\015\015")
print ( "Delete:\033]0;New Window title\007\015")
print ( "Delete:\x900;New Window title\x9c")


print ( "tab1\ttab2\t\ttab3\t\t\tend")

# delete until EOL
print ( "Delete:\033[sTEST s - DELETED\n")
print ( "Delete:\033[uTEST u - DELETED\n")
print ( "Delete:\033[KTEST K - DELETED\033[K\033[K\033[K xxx blablabla\n")
print ( "Delete:\033[1KTEST K1 - DELETED\033[K\033[K\033[2K xxx blablabla\n")

print ( "Delete:\033[0GTEST G - DELETED\033[0G\033[0G\033[0G xxx blablabla\n")

# but not with grep --color
print ( "\033[01;31m\033[KGREP COLOR SEQUENCE\033[m\033[K 0;\n")

print ( "1234567890 12345 67890 1234567890 12345 67890 1234567890123456789012345678901234567890123456789012345678901234567890")
print ( "Ignore:\033[=1hEND\n")
print ( "Ignore:\033[?25lEND\n")
print ( "Ignore:\033[0GEND\n")

#ESC[1GESC[KESC[34m 0:00.60ESC[m^O /usr/bin/gmake -f client.mkESC[m^O
print ( "\0337\0338\0337\0338\0337\0338\n")
