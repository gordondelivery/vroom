#ifndef CVRP_ROUTE_FIX_H
#define CVRP_ROUTE_FIX_H

/*

This file is part of VROOM.

Copyright (c) 2015-2022, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "algorithms/local_search/operator.h"

namespace vroom::cvrp {

class RouteFix : public ls::Operator {
private:
  void compute_gain() override;

protected:
  std::vector<Index> heuristic_route;

public:
  RouteFix(const Input& input,
           const utils::SolutionState& sol_state,
           RawRoute& s_route,
           Index s_vehicle);

  bool is_valid() override;

  void apply() override;

  std::vector<Index> addition_candidates() const override;

  std::vector<Index> update_candidates() const override;
};

} // namespace vroom::cvrp

#endif
