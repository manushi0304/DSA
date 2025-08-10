class Solution {
public:
   int kthGrammar(int n, int k) {
    if (n == 1) return 0; // base case

    // parent position in the previous row
    int parent = kthGrammar(n - 1, (k + 1) / 2);

    // if k is odd → same as parent, if k is even → flipped
    if (k % 2 == 1) return parent;
    else return 1 - parent;
}

};