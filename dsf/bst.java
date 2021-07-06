//Implement binary search tree and perform following operations: a. Insert, Delete, Display 
import java.util.Scanner;

class Node {
    int data;
    Node left,right;
    Node(int x){
        data=x;
        left=null;
        right=null;
    }
    Node(){
        left=null;
        right=null;
    }
}
class BST{
    //function will perform inorder traversal 
    Node root=new Node();
    BST(){
        root=null;
    }
    BST(int x){
        root.data=x;
    }
    void insert(int x){
        root=insert_1(root,x);
    }
    private Node insert_1(Node root,int x){
       //if root is null create a new node and return it 
        if(root==null){
            Node root1=new Node();
            root1.data=x;
            return root1;
        }
        //if the input is less than root node than take left or right 
        else if(root.data>x){
            root.left=insert_1(root.left, x);
        }
        else if(root.data<x){
            root.right=insert_1(root.right,x);
        }
        else{
            System.out.println("DUPLICATE KEY!!!");
        }
        return root;
    }
    void display(){
        display_1(root);
    }
    //this function will perform inorder traversal of binary search tree
    private void display_1(Node root){
        if(root!=null){
            display_1(root.left);
            System.out.print(root.data+" ");
            display_1(root.right);
        }
    }
    void delete(int x){
        root=delete_1(root,x);
    }
    private Node delete_1(Node root,int x){
       //pointer used to store parent node of current node
        if(root==null){
            return null;
        }
        //starting with root node here 
        if(root.data>x){
            root.left=delete_1(root.left,x);
        }
        else if(root.data<x){
            root.right=delete_1(root.right,x);
        }
        else{
            if(root.left==null){
               //if key is less than current go to left or right according to conditioon 
                return root.right;
            }
            if(root.right==null){
                return root.left;
            }
            int k=left_max(root.left);
            root.data=k;
            root.left=delete_1(root.left,k);
        }
        return root;
    }
    private int left_max(Node x){
        int j=x.data;
        while(x.right!=null){
            j=x.right.data;
            x=x.right;
        }
        return j;
    }
}

public class Main {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        BST v=new BST();
        while(true){
            System.out.println("PRESS 1 FOR NEW NODE\n2 FOR DELETING NODE\n3 WILL DISPLAY BINARY SEARCH TREE \nPRESS ANY KEY TO EXIT ");
            int i=sc.nextInt();
            if(i==1){
                System.out.println("ENTER KEY ONE BY ONE ");
                int j=sc.nextInt();
                v.insert(j);
            }
            else if(i==2){
                System.out.println("ENTER KEY WHICH HAS TO BE DELETED--");
                int j=sc.nextInt();
                v.delete(j);
            }
            else if(i==3){
                v.display();
                System.out.println();
            }
            else{
                break;
            }
        }
        sc.close();
    }
}
