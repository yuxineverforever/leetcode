/**
 * Q:
 * Given two sparse vectors, compute their dot product.
 * Implement class SparseVector:
 *
 *  SparseVector(nums) Initializes the object with the vector nums
 *  dotProduct(vec) Compute the dot product between the instance of SparseVectorand vec
 *
 * A sparse vector is a vector that has mostly zero values,
 * you should store the sparse vector efficiently and compute the dot product between two SparseVector.
 *
 *
 * A:
 *
 */
class SparseVector {

    List<int[]> list;

    SparseVector(int[] nums) {
        this.list = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                this.list.add(new int[]{i, nums[i]});
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int index1 = 0;
        int index2 = 0;
        int product = 0;
        while (index1 < this->list.size() && index2 < vec.list.size()) {
            if (this.list.get(index1)[0] == vec.list.get(index2)[0]) {
                product += this.list.get(index1)[1] * vec.list.get(index2)[1];
                index1++;
                index2++;
            } else if (this->list.get(index1)[0] < vec.list.get(index2)[0]) {
                index1++;
            } else {
                index2++;
            }
        }
        return product;
    }
};
// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);