/***************************************************************************
                          version.h  -  description
                             -------------------
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

#ifndef VERSION_H
#define VERSION_H

#include <string>

#define ANSIFILTER_VERSION "2.18"

#define ANSIFILTER_URL   "http://www.andre-simon.de/"
#define ANSIFILTER_EMAIL "a.simon@mailbox.org"

class Info
{
public:

    static std::string getVersion() {
        return ANSIFILTER_VERSION;
    }

    static std::string getWebsite() {
        return ANSIFILTER_URL;
    }

    static std::string getEmail() {
        return ANSIFILTER_EMAIL;
    }
};

#endif
