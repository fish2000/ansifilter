#!/usr/bin/python
#-*- coding: utf-8 -*-

import sys

# Generate a one line input file for Github CI tests
sys.stdout.write ( "BEGIN \033[1;4mBold\033[0m ")
sys.stdout.write ( "\033[4mUnderline\033[0m ")
sys.stdout.write ( "\033[3mItalic\033[0m ")
sys.stdout.write ( "\033[5mBlink\033[0m ")
sys.stdout.write ( "\033[8mHide\033[0m ")
sys.stdout.write ( "\033[30mBlack\033[0m ")
sys.stdout.write ( "\033[31mRed\033[0m ")
sys.stdout.write ( "\033[32mGreen\033[0m ")
sys.stdout.write ( "\033[33mYellow\033[0m ")
sys.stdout.write ( "\033[34mBlue\033[0m ")
sys.stdout.write ( "\033[35mMagenta\033[0m ")
sys.stdout.write ( "\033[36mCyan\033[0m ")
sys.stdout.write ( "\033[37mWhite\033[0m END")

# should result in "BEGIN Bold Underline Italic Blink Hide Black Red Green Yellow Blue Magenta Cyan White END"
