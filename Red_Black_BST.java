package searching;

public class Red_Black_BST {
	private static final boolean BLACK=false;
	private static final boolean RED=true;
	private  Node root=null;

	private class Node{
		int val;
		Node left,right;
		boolean color=BLACK;
		Node(int val,boolean color){
			this.val=val;
			this.color=color;
			left=right=null;
		}
	}
	 boolean isRed(Node x) {
		if(x==null) return BLACK;
		return x.color==RED;
	}
	 Node rotateLeft(Node curr) {
		Node x=curr.right;
		curr.right=x.left;
		x.left=curr;
		x.color=curr.color;
		curr.color=RED;
		return x;

	}
	 Node rotateRight(Node curr) {
		Node x=curr.left;
		curr.left=x.right;
		x.right=curr;
		x.color=curr.color;
		curr.color=RED;
		return x;
	}
	 void flipColors(Node curr) {
		curr.left.color=curr.right.color=BLACK;
		curr.color=RED;

	}
	 public void insert(int val) {
		root=insert(root,val);


	}
	 private Node insert(Node curr,int val) {
		if(curr==null)
			return new Node(val,RED);
		if(val < curr.val)
			curr.left=insert(curr.left,val);
		else if(val > curr.val)
			curr.right=insert(curr.right,val);

		if(!isRed(curr.left) && isRed(curr.right))
			curr=rotateLeft(curr);
		if(isRed(curr.left) && isRed(curr.left.left))
			curr=rotateRight(curr);
		if(isRed(curr.left) && isRed(curr.right))
			flipColors(curr);
		return curr;

	}
	 public void inOrder() {
		 inOrder(root);
	 }
	private void inOrder(Node root) {
		 if(root==null)
			 return;
		 inOrder(root.left);
		 System.out.printf("%d ",root.val);
		 inOrder(root.right);
	 }


}
