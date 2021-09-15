import java.util.LinkedList;
import java.util.Queue;

public class bfsanddfstree {
	static class TreeNode{
	int data;
	TreeNode left , right;

	public TreeNode(int key){
		data = key;
		left = right = null;
	}
}

static void preorder(TreeNode TreeNode){
	if(TreeNode == null)
		return;

	//Traverse through root 
	System.out.println(TreeNode.data + " ");
	//Traverse left
	preorder(TreeNode.left);
	//Traverse right 
	preorder(TreeNode.right);
}

static void inorder(TreeNode TreeNode){
	if(TreeNode == null)
		return;

	//Traverse left
	inorder(TreeNode.left);
	//Traverse through root 
	System.out.println(TreeNode.data + " ");
	//Traverse right 
	inorder(TreeNode.right);
}

static void postorder(TreeNode TreeNode) {
	if(TreeNode == null)
	return;

	//Traverse Left 
	postorder(TreeNode.left);
	//Traverse Right 
	postorder(TreeNode.right);
	//Traverse root 
	System.out.println(TreeNode.data + " ");
}
static void printLevelOrder(TreeNode root) {
	Queue<TreeNode> queue = new LinkedList<TreeNode>();
	queue.add(root);
	while(!queue.isEmpty()) {
		TreeNode tempNode = queue.poll();
		System.out.println(tempNode.data + " ");

		//add child on the left to the queue
		if(tempNode.left != null) {
			queue.add(tempNode.left);
		}
		//add child on the right to the queue
		if(tempNode.right !=null){
			queue.add(tempNode.right);
		}
	}
}

public static void main(String args[])
{
	TreeNode root = new TreeNode(0);
	root.left = new TreeNode(1);
	root.right = new TreeNode (2);
	root.left.left = new TreeNode(3);
	root.right.right = new TreeNode(4);
	System.out.println("Inorder Traversal");
	inorder(root);

	System.out.println("\n Preorder Traversal");
	preorder(root);

	System.out.println("\n Postorder Traversal");
	postorder(root);

	System.out.println("\n Level Order Traversal");
	printLevelOrder(root);

	}
}