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
#ifndef REGISTER_POOL_HH
#define REGISTER_POOL_HH

#include <backend/assembly.hh>
#include <iostream>
#include <ir/cfg.hh>
#include <unordered_map>

// For ARM-v7 32-bit backend.

/**
 * @brief This class implements register allocation algorithms (linear-scan
 * alogrithm).
 * @ref   Poletto, Massimiliano, and Vivek Sarkar. "Linear scan register
 *        allocation." ACM Transactions on Programming Languages and Systems
 *       (TOPLAS) 21.5 (1999): 895-913.
 *
 */
namespace compiler::reg {
// TODO: Add a class for LiveRange or LiveInternal which defines the "DEF-USE"
// CHAIN.
// TODO: Perform analysis over the CFG for each function.
/**
 * @brief This class defines pool for active registers.
 *
 */
typedef class Allocator {
 private:
  /**
   * @brief A hash map that stores the availability of each registers of ARM.
   *
   */
  std::unordered_map<std::string, bool> register_free_map;

  /**
   * @brief A hash that stores the the mapping of virtual registers.
   *
   */
  std::unordered_map<std::string, std::string> virtual_to_physical;

  /**
   * @brief Records the number of free registers. If there is no free registers
   * anymore, we should spill virtual registers onto the stack.
   *
   */
  uint32_t free_registers;

  const compiler::ir::cfg cfg_blocks;

 public:
  Allocator() = delete;

  Allocator(const compiler::ir::cfg& cfg_blocks);

  void generate_code(std::ostream& os = std::cerr);

 protected:
  /**
   * @brief Get a free register from the register pool.
   *
   * @return std::string
   */
  std::string get_free_register(void);

  /**
   * @brief Set an occupied register to be free.
   *
   * @param reg_name
   */
  void set_free_register(const std::string& reg_name);

  uint32_t free_num(void) { return free_registers; }

} Allocator;
}  // namespace compiler::reg

#endif