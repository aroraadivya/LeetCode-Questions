/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> sortedElements = new ArrayList<>();
        collectInOrder(root, sortedElements);
        return constructBalancedBST(sortedElements, 0, sortedElements.size() - 1);
    }

    private void collectInOrder(TreeNode node, List<Integer> sortedElements) {
        if (node == null) {
            return;
        }
        collectInOrder(node.left, sortedElements);
        sortedElements.add(node.val);
        collectInOrder(node.right, sortedElements);
    }

    private TreeNode constructBalancedBST(List<Integer> elements, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = start + (end - start) / 2;
        TreeNode node = new TreeNode(elements.get(mid));
        node.left = constructBalancedBST(elements, start, mid - 1);
        node.right = constructBalancedBST(elements, mid + 1, end);
        return node;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}