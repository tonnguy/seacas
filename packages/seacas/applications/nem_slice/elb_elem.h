/*
 * Copyright(C) 1999-2020, 2022, 2023, 2024 National Technology & Engineering Solutions
 * of Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
 * NTESS, the U.S. Government retains certain rights in this software.
 *
 * See packages/seacas/LICENSE for details
 */
#pragma once

/* Define element types */
enum class ElementType {
  SPHERE,
  BAR2,
  BAR3,
  QUAD4,
  QUAD8,
  QUAD9,
  SHELL4,
  SHELL8,
  SHELL9,
  TRI3,
  TRI4,
  TRI6,
  TRI7,
  TSHELL3,
  TSHELL4,
  TSHELL6,
  TSHELL7,
  HEX8,
  HEX16,
  HEX20,
  HEX27,
  HEXSHELL,
  TET4,
  TET10,
  TET8,
  TET14,
  TET15,
  WEDGE6,
  WEDGE12,
  WEDGE15,
  WEDGE16,
  WEDGE20,
  WEDGE21,
  PYRAMID5,
  PYRAMID13,
  PYRAMID14,
  PYRAMID18,
  PYRAMID19,
  SHELL2,
  SHELL3,
  BAR1D2,
  BAR1D3,
  NULL_EL
};

extern const char *elem_name_from_enum(ElementType elem_type);

extern ElementType get_elem_type(const char *elem_name, /* ExodusII element name */
                                 int         num_nodes, /* Number of nodes in the element */
                                 int         num_dim    /* Number of dimensions of the mesh */
);

extern int get_elem_info(int         info,     /* The requested information */
                         ElementType elem_type /* The element type */
);

template <typename INT>
int get_side_id(ElementType etype, const INT *connect, int nsnodes, INT side_nodes[],
                int skip_check, int partial_adj);

template <typename INT>
int get_side_id_hex_tet(ElementType etype,       /* The element type */
                        const INT  *conn,        /* The element connectivity */
                        int         nsnodes,     /* The number of side nodes */
                        const INT   side_nodes[] /* The list of side node IDs */
);

template <typename INT>
int ss_to_node_list(ElementType etype,         /* The element type */
                    const INT  *connect,       /* The element connectivity */
                    int         side_num,      /* The element side number */
                    INT         ss_node_list[] /* The list of side node IDs */
);

template <typename INT>
int get_ss_mirror(ElementType etype,             /* The element type */
                  const INT  *ss_node_list,      /* The list of side node IDs */
                  int         side_num,          /* The element side number */
                  INT         mirror_node_list[] /* The list of the mirror side node IDs */
);

/* Define element info requests */
#define NNODES      0
#define NDIM        2
#define NSIDE_NODES 4
#define NSIDES      5

/* Define for the maximum number of nodes on an element side/face */
#define MAX_SIDE_NODES 9
/*
 * Define for the maximum number of sides (and hence communications
 * entries) that an element can have
 */
#define MAX_ELEM_SIDES 6

bool is_hex(ElementType etype);
bool is_tet(ElementType etype);
bool is_wedge(ElementType etype);
bool is_pyramid(ElementType etype);
bool is_3d_element(ElementType etype);
