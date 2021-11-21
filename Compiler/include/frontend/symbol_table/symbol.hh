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
#ifndef SYMBOL_HH
#define SYMBOL_HH

#include <common/types.hh>
#include <ir/ir.hh>
#include <string>
#include <vector>

namespace compiler {
// To avoid circular includes error.
// 1. Item_literal <- compiler::symbol_table <- compiler::ir::context <-
// Item_literal
// 2. Another way is to define seperate virtual functions for each node type.
// But Item_literal is inherited from Item_expr.
class Item_literal;

/**
 * @brief Class for symbols (basic type).
 *
 */
class Symbol_table;
typedef class Symbol {
 protected:
  std::vector<ir::Operand*> shape;

  std::string name;

  const symbol_type type;

  bool is_pointer;  // Array is pointer type.

  std::string value;

 public:
  Symbol() = delete;

  Symbol(const std::string& name, const symbol_type& type,
         const bool& is_pointer = false,
         const std::vector<ir::Operand*>& shape = {});

  Symbol(const Symbol& symbol);

  virtual void set_value(const std::string& value) { this->value = value; }

  virtual void add_shape(ir::Operand* const shape) {
    this->shape.emplace_back(shape);
  }

  virtual std::vector<ir::Operand*> get_shape(void) const { return shape; }

  virtual bool is_const(void) const { return false; }

  virtual std::string get_name(void) const { return name; }

  virtual void set_name(const std::string& name) { this->name = name; }

  virtual symbol_type get_type(void) const { return type; }

  virtual bool get_is_pointer(void) const { return is_pointer; }

  virtual ~Symbol() = default;
} Symbol;

typedef class Symbol_const : public Symbol {
 protected:
  std::vector<std::string> values;

  std::string value;

 public:
  Symbol_const() = delete;

  Symbol_const(const std::string& name, const symbol_type& type,
               const std::string& value, const bool& is_pointer = false,
               const std::vector<std::string>& values = {});

  Symbol_const(const Symbol_const& symbol_const);

  virtual bool is_const(void) const override { return true; }

  virtual std::string get_value(void) const { return value; }

  virtual std::vector<std::string> get_values(void) const { return values; }
} Symbol_const;
}  // namespace compiler

#endif