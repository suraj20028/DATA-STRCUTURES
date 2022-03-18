#include<stdio.h>
#include<stdlib.h>
 
typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}node;
 
node *create();
void insert(node *,node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
 node * minValueNode( node* );
 node* deleteNode(node* root, int key);
int main()
{
	char ch;
	node *root=NULL,*temp;
    int choice,item;
    while(1)
    {
    printf(" 1. Create/Insert\n 2. Traversal (Preorder)\n 3. Traversal (inorder)\n 4. Traversal (postorder)\n 5. Delele \n");
    printf("Enter your choice = ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
	
	do
	{
		temp=create();
		if(root==NULL)
			root=temp;
		else	
			insert(root,temp);
			
		printf("\n Do you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'|| ch=='Y');
	break;
    case 2:
    
	printf("\n Preorder Traversal: ");
	preorder(root); break;
    case 3:
    
	printf("\n inorder Traversal: ");
	inorder(root); break;
    case 4:
    
	printf("\n postorder Traversal: ");
	postorder(root); break;
    case 5: printf("Enter the element to be deleted");
            scanf("%d",&item);
           root= deleteNode(root, item); break;
    case 6: exit(0);
    }
    }
	return 0;
    
}
 
node *create()
{
	node *temp;
	printf("\n Enter data:");
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}
 
void insert(node *root,node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}
	
	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}
 
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
        inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
        postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

node * minValueNode( node* x){
    node* current = x;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}
node* deleteNode(node* root, int key){
    node * temp;
   if (root == NULL) return root;
      if (key < root->data)
         root->left = deleteNode(root->left, key);
      else if (key > root->data)
         root->right = deleteNode(root->right, key);
   else{
      if (root->left == NULL){
         temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         temp = root->left;
         free(root);
         return temp;
      }
      temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
   }
   return root;
}