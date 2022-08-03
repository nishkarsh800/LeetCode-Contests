// PROBLEM :-- Booking Concert Tickets in Groups //

/* A concert hall has n rows numbered from 0 to n - 1, each with m seats, numbered from 0 to m - 1. You need to design a ticketing system that can allocate seats in the following cases:

If a group of k spectators can sit together in a row.
If every member of a group of k spectators can get a seat. They may or may not sit together.
Note that the spectators are very picky. Hence:

They will book seats only if each member of their group can get a seat with row number less than or equal to maxRow. maxRow can vary from group to group.
In case there are multiple rows to choose from, the row with the smallest number is chosen. If there are multiple seats to choose in the same row, the seat with the smallest number is chosen.
Implement the BookMyShow class:

BookMyShow(int n, int m) Initializes the object with n as number of rows and m as number of seats per row.
int[] gather(int k, int maxRow) Returns an array of length 2 denoting the row and seat number (respectively) of the first seat being allocated to the k members of the group, who must sit together. In other words, it returns the smallest possible r and c such that all [c, c + k - 1] seats are valid and empty in row r, and r <= maxRow. Returns [] in case it is not possible to allocate seats to the group.
boolean scatter(int k, int maxRow) Returns true if all k members of the group can be allocated seats in rows 0 to maxRow, who may or may not sit together. If the seats can be allocated, it allocates k seats to the group with the smallest row numbers, and the smallest possible seat numbers in each row. Otherwise, returns false.
 

Example 1:

Input
["BookMyShow", "gather", "gather", "scatter", "scatter"]
[[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
Output
[null, [0, 0], [], true, false]

Explanation
BookMyShow bms = new BookMyShow(2, 5); // There are 2 rows with 5 seats each 
bms.gather(4, 0); // return [0, 0]
                  // The group books seats [0, 3] of row 0. 
bms.gather(2, 0); // return []
                  // There is only 1 seat left in row 0,
                  // so it is not possible to book 2 consecutive seats. 
bms.scatter(5, 1); // return True
                   // The group books seat 4 of row 0 and seats [0, 3] of row 1. 
bms.scatter(5, 1); // return False
                   // There is only one seat left in the hall.
 

Constraints:

1 <= n <= 5 * 104
1 <= m, k <= 109
0 <= maxRow <= n - 1
At most 5 * 104 calls in total will be made to gather and scatter. */

// Approach

Given a concert hall has n rows numbered from 0 to n - 1.
Each with m seats, numbered from 0 to m - 1.
Group of k spectators can sit together in a row.
Every member of a group of k spectators can get a seat.
They may or may not sit together.
Book seats only if each member of their group can get a seat with row number less than or equal to maxRow.
Choose the row with the smallest number when there are multiple rows to choose from.
Choose the seat with the smallest number when there are multiple seats to choose in the same row.

struct SegmentTreeNode {
  int lo;
  int hi;
  unique_ptr<SegmentTreeNode> left;
  unique_ptr<SegmentTreeNode> right;
  int max;
  long sum;
  SegmentTreeNode(int lo, int hi, unique_ptr<SegmentTreeNode>&& left,
                  unique_ptr<SegmentTreeNode>&& right, int max, long sum)
      : lo(lo),
        hi(hi),
        left(move(left)),
        right(move(right)),
        max(max),
        sum(sum) {}
};

class SegmentTree {
 public:
  SegmentTree(int n, int m) : m(m), root(move(build(0, n - 1))) {}

  vector<int> maxRange(int k, int maxRow) {
    return maxRange(root, k, maxRow);
  }

  long sumRange(int maxRow) {
    return sumRange(root, 0, maxRow);
  }

  // minus k max and sum from seats row
  void minus(int row, int k) {
    minus(root, row, k);
  }

 private:
  const int m;
  unique_ptr<SegmentTreeNode> root;

  unique_ptr<SegmentTreeNode> build(int l, int r) {
    if (l == r)
      return make_unique<SegmentTreeNode>(l, r, nullptr, nullptr, m, m);
    const int mid = (l + r) / 2;
    unique_ptr<SegmentTreeNode> left = build(l, mid);
    unique_ptr<SegmentTreeNode> right = build(mid + 1, r);
    return make_unique<SegmentTreeNode>(l, r, move(left), move(right),
                                        max(left->max, right->max),
                                        left->sum + right->sum);
  }

  vector<int> maxRange(unique_ptr<SegmentTreeNode>& root, int k, int maxRow) {
    if (root->lo == root->hi) {
      if (root->sum < k || root->lo > maxRow)
        return {};
      return {root->lo, m - static_cast<int>(root->sum)};  // {row, col}
    }
    // greedily search the left subtree
    if (root->left->max >= k)
      return maxRange(root->left, k, maxRow);
    return maxRange(root->right, k, maxRow);
  }

  long sumRange(unique_ptr<SegmentTreeNode>& root, int i, int j) {
    if (root->lo == i && root->hi == j)
      return root->sum;
    const int mid = (root->lo + root->hi) / 2;
    if (j <= mid)
      return sumRange(root->left, i, j);
    if (i > mid)
      return sumRange(root->right, i, j);
    return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
  }

  void minus(unique_ptr<SegmentTreeNode>& root, int row, int k) {
    if (!root)
      return;
    if (root->lo == root->hi && root->hi == row) {
      root->max -= k;
      root->sum -= k;
      return;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (row <= mid)
      minus(root->left, row, k);
    else
      minus(root->right, row, k);
    root->max = max(root->left->max, root->right->max);
    root->sum = root->left->sum + root->right->sum;
  }
};

class BookMyShow {
 public:
  BookMyShow(int n, int m) : tree(n, m), seats(n, m) {}

  vector<int> gather(int k, int maxRow) {
    const auto res = tree.maxRange(k, maxRow);
    if (res.size() == 2) {
      const int row = res[0];
      tree.minus(row, k);
      seats[row] -= k;
    }
    return res;
  }

  bool scatter(int k, int maxRow) {
    if (tree.sumRange(maxRow) < k)
      return false;

    while (k > 0)
      if (seats[minVacantRow] >= k) {
        tree.minus(minVacantRow, k);
        seats[minVacantRow] -= k;
        k = 0;
      } else {
        tree.minus(minVacantRow, seats[minVacantRow]);
        k -= seats[minVacantRow];
        seats[minVacantRow] = 0;
        ++minVacantRow;
      }

    return true;
  }

 private:
  SegmentTree tree;
  vector<int> seats;  // remain seats at each row
  int minVacantRow = 0;
};

// Time Complexity: Constructor: O(n), O(logn)
// Space Complexity: O(n)

