/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBFALLTERGEIST_ACMFILETYPE_H
#define LIBFALLTERGEIST_ACMFILETYPE_H

// C++ standard includes

// libfalltergeist includes
#include "../src/DatFileItem.h"

namespace libfalltergeist
{

class AcmFileType : public DatFileItem
{
protected:
    virtual void _initialize();
public:
    AcmFileType(std::shared_ptr<DatFileEntry> datFileEntry);
    AcmFileType(std::ifstream* stream);
    ~AcmFileType();
    void test();
};

}
#endif // LIBFALLTERGEIST_ACMFILETYPE_H
