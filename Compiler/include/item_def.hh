/*
 Copyright (c) 2021 Haobin Chen

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef ITEM_DEC_HH
#define ITEM_DEC_HH

#include <item.hh>

namespace compiler {

typedef class Item_def : public Item {
public:
    virtual Item::type get_type(void) const override { return Item::type::DEF_ITEM; }

    virtual ~Item_def() override = default;
} Item_Def;
} // namespace compiler

#endif