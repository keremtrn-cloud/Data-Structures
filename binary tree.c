dlib.h>


struct node{
	
	int data;
	struct node* Ltree;
	struct node* Rtree;
};

struct node* insert(struct node*temp,int x){
	
	
	if(temp == NULL){
	temp = malloc(sizeof(struct node));
	
	temp->data = x;
	temp->Ltree=NULL;
	temp->Rtree=NULL;
    } 
	else if(temp->data<x){
	
	    temp->Ltree = insert(temp->data,x);	
   }
	else if(temp->data>x){
	
		
		temp->Rtree= insert(temp->data,x);
   }
    return  temp;
}
void inorder(struct node* root)
{
    if (root != NULL) {
    	struct node *root = (struct node*)malloc(sizeof(struct node));
        inorder(root->Ltree);
        printf("%d \n", root->data);
        inorder(root->Rtree);
    }
}
void prenorder(struct node* root)
{
    if (root != NULL) {
    	struct node *root = (struct node*)malloc(sizeof(struct node));
    	printf("%d \n", root->data);
        preorder(root->Ltree);
        preorder(root->Rtree);
    }
}
void postnorder(struct node* root)
{
    if (root != NULL) {
    	struct node *root = (struct node*)malloc(sizeof(struct node));
        postorder(root->Ltree);
        postorder(root->Rtree);
        printf("%d \n", root->data);
    }
}

void search(struct node*temp,int x){
	
	if(temp == NULL){
		printf("Number not found.");
	}
	else if(temp->data == x){
		printf("Number found.");
	}
	else if(temp->data>x){
		search(temp->Ltree,x);
	}
	else if(temp->data<x){
		search(temp->Rtree,x);
	}
}

int main( )	{

	struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    search(root,50);
    
    inorder(root);
 
    return 0;
}
