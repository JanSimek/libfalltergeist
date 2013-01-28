/*
 * Copyright 2012-2013 Falltergeist Developers.
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

#include "../src/AafFileType.h"
#include "../src/AafGlyph.h"
#include "../src/DatFileItem.h"

namespace libfalltergeist
{

AafFileType::AafFileType(DatFileItem * datFileItem): _datFileItem(datFileItem)
{
    _glyphs = 0;
    open();
}

AafFileType::~AafFileType()
{
    delete _glyphs;
}

void AafFileType::open()
{
    _glyphs = new std::vector<AafGlyph *>;
    _datFileItem->setPosition(0);

    // AAFF Signature
    _datFileItem->skipBytes(4);

    setMaximumHeight(_datFileItem->readUint16());

    setHorizontalGap(_datFileItem->readUint16());

    setSpaceWidth(_datFileItem->readUint16());

    setVerticalGap(_datFileItem->readUint16());

    unsigned int * _dataOffsets = new unsigned int[256];

    // glyphs descriptions
    for (unsigned int i = 0; i != 256; ++i)
    {
        AafGlyph * glyph = new AafGlyph();
        glyph->setWidth(_datFileItem->readUint16());
        glyph->setHeight(_datFileItem->readUint16());
        _dataOffsets[i] = _datFileItem->readUint32();
        _glyphs->push_back(glyph);
    }

    //glyphs data
    for (unsigned int i = 0; i != 256; ++i)
    {
        _datFileItem->setPosition(0x080C + _dataOffsets[i]);
        for (unsigned int j = 0; j != _glyphs->at(i)->getWidth()*_glyphs->at(i)->getHeight(); ++j)
        {
            _glyphs->at(i)->getData()->push_back(_datFileItem->readUint8());
        }
    }

    delete [] _dataOffsets;
}

/**
 * Alias to AafFileType::getDatFileItem
 * @brief AafFileType::datFileItem
 * @return
 */
DatFileItem * AafFileType::datFileItem()
{
    return getDatFileItem();
}

DatFileItem * AafFileType::getDatFileItem()
{
    return _datFileItem;
}

/**
 * Alias to AafFileType::getGlyphs
 * @brief AafFileType::glyphs
 * @return
 */
std::vector<AafGlyph *> * AafFileType::glyphs()
{
    return getGlyphs();
}

std::vector<AafGlyph *> * AafFileType::getGlyphs()
{
    return _glyphs;
}

/**
 * Alias to AafFileType::getHorizontalGap
 * @brief AafFileType::horizontalGap
 * @return
 */
unsigned short AafFileType::horizontalGap()
{
    return getHorizontalGap();
}

unsigned short AafFileType::getHorizontalGap()
{
    return _horizontalGap;
}

void AafFileType::setHorizontalGap(unsigned short gap)
{
    _horizontalGap = gap;
}

/**
 * Alias to AafFileType::getMaximumHeight
 * @brief AafFileType::maximumHeight
 * @return
 */
unsigned short AafFileType::maximumHeight()
{
    return getMaximumHeight();
}

unsigned short AafFileType::getMaximumHeight()
{
    return _maximumHeight;
}

void AafFileType::setMaximumHeight(unsigned short height)
{
    _maximumHeight = height;
}

/**
 * Alias to AafFileType::getSpaceWidth
 * @brief AafFileType::spaceWidth
 * @return
 */
unsigned short AafFileType::spaceWidth()
{
    return getSpaceWidth();
}

unsigned short AafFileType::getSpaceWidth()
{
    return _spaceWidth;
}

void AafFileType::setSpaceWidth(unsigned short width)
{
    _spaceWidth = width;
}

/**
 * Alias to AafFileType::getVerticalGap
 * @brief AafFileType::verticalGap
 * @return
 */
unsigned short AafFileType::verticalGap()
{
    return getVerticalGap();
}

unsigned short AafFileType::getVerticalGap()
{
    return _verticalGap;
}

void AafFileType::setVerticalGap(unsigned short gap)
{
    _verticalGap = gap;
}

}
