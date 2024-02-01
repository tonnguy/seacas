// Copyright(C) 1999-2022, 2024 National Technology & Engineering Solutions
// of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
// NTESS, the U.S. Government retains certain rights in this software.
//
// See packages/seacas/LICENSE for details

#pragma once

#include "ioss_export.h"

#include "Ioss_CodeTypes.h"       // for IntVector
#include "Ioss_ElementTopology.h" // for ElementTopology

// STL Includes

namespace Ioss {
  class IOSS_EXPORT Edge2D2 : public Ioss::ElementTopology
  {

  public:
    static const char *name;

    static void factory();
    Edge2D2(const Edge2D2 &) = delete;

    ElementShape shape() const override { return ElementShape::LINE; }
    int          spatial_dimension() const override;
    int          parametric_dimension() const override;
    bool         is_shell() const override { return false; }
    int          order() const override;

    int number_corner_nodes() const override;
    int number_nodes() const override;
    int number_edges() const override;
    int number_faces() const override;

    int number_nodes_edge(int edge = 0) const override;
    int number_nodes_face(int face = 0) const override;
    int number_edges_face(int face = 0) const override;

    Ioss::IntVector edge_connectivity(int edge_number) const override;
    Ioss::IntVector face_connectivity(int face_number) const override;
    Ioss::IntVector element_connectivity() const override;

    Ioss::ElementTopology *face_type(int face_number = 0) const override;
    Ioss::ElementTopology *edge_type(int edge_number = 0) const override;

  protected:
    Edge2D2();
  };
} // namespace Ioss
