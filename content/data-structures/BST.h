/**
 * Author: Simon Lindholm
 * Date: 2016-03-22
 * License: CC0
 * Source: hacKIT, NWERC 2015
 * Description: Configurable BST
 * To get a map, change \texttt{null\_type}.
 * Time: O(\log N)
 */
#pragma once

using namespace detail;

#define left get_l_child() #define right get_r_child()
#define value m_p_nd->m_value // Set: T Map: pair<K, V>
#define meta m_p_nd->get_metadata()#define valid m_p_nd
struct Meta { int sum; };
template<typename TIT, typename CTIT, typename C, typename A>
struct CustomUpdate { typedef Meta metadata_type;
  template<typename T> void operator()(T n, T null) {
    Meta &data = n.meta; data.sum = n.value;
    if (n.left.m_p_nd) data.sum += n.left.meta.sum;
    if (n.right.m_p_nd) data.sum += n.right.meta.sum;
  } template<typename T> int sum_lt(T n, int k) {
    if (!n.valid) return 0; int r = 0, v = n.value;
    if (v < k) r += v;
    if (n.left.valid && v < k) r += n.left.meta.sum;
    else       r += sum_lt(n.left, k);
    if (v < k) r += sum_lt(n.right, k);
    return r;
  }
  int sum_lt(int k) { return sum_lt(node_begin(), k); }
  virtual TIT node_begin() = 0;
  virtual CTIT node_begin() const = 0;
};
#undef left #undef right #undef value
#undef meta #undef valid
typedef tree<int, null_type, less<int>, rb_tree_tag, CustomUpdate> myset;
