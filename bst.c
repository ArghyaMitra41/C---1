#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst *left,*right;
	int info;
};
struct bst *bst_ins(struct bst *root,int n)
{
	struct bst *par=NULL;
	struct bst *loc,*ptr;
	loc=root;
	while(loc!=NULL)
	{
		if(n==loc->info)
		{
			printf("\nDuplicate Value");
			return(root);
		}
		par=loc;
		if(n<loc->info)
			loc=loc->left;
		else
			loc=loc->right;
	}
	ptr=(struct bst *)malloc(sizeof(struct bst));
	ptr->info=n;
	ptr->left=NULL;
	ptr->right=NULL;
	if(par==NULL)
		root=ptr;
	else if(n<par->info)
		par->left=ptr;
	else
		par->right=ptr;
	return(root);
}
void preorder(struct bst *root)
{
	struct bst *temp;
	temp=root;
	if(temp==NULL)
		return;
	else
	{
		printf("%d ",temp->info);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct bst *root)
{
	struct bst *temp=root;
	if(temp==NULL)
		return;
	else
	{	inorder(temp->left);
		printf("%d ",temp->info);
		inorder(temp->right);
	}
}
void postorder(struct bst *root)
{
	struct bst *temp=root;
	if(temp==NULL)
		return;
	else
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->info);
	}
}
struct bst *del_caseAB(struct bst *root,struct bst *loc,struct bst *par)
{
	struct bst *child;
	if(loc->left==NULL && loc->right==NULL)
		child=NULL;
	else if(loc->left!=NULL)
		child=loc->left;
	else
		child=loc->right;
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=child;
		else
			par->right=child;
	}
	else
		root=child;
	return(root);
}
struct bst *del_caseC(struct bst *root,struct bst *loc,struct bst *par)
{
	struct bst *suc,*save,*parsuc,*ptr;
	ptr=loc->right;
	save=loc;
	while(ptr->left!=NULL)
	{
		save=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=save;
	root=del_caseAB(root,suc,parsuc);
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=suc;
		else
			par->right=suc;
	}
	else
		root=suc;
	suc->left=loc->left;
	suc->right=loc->right;
	return(root);
}
struct bst *bst_del(struct bst *root, int n)
{
        struct bst *loc,*par;
        loc=root;
        par=NULL;
        while(loc!=NULL && n!=loc->info)
        {
                par=loc;
                if(n<loc->info)
                        loc=loc->left;
                else
                        loc=loc->right;
        }
        if(loc==NULL)
        {
                printf("\nValue Not Found");
                exit(0);
        }
        if(loc->left!=NULL && loc->right!=NULL)
                root=del_caseC(root,loc,par);
        else
                root=del_caseAB(root,loc,par);
        free(loc);
        return(root);
}
int main()
{
        int i,n,ch;
        struct bst *root=NULL;
        while(1)
        {
                printf("\n1.Insert\n2.Preorder Traverse\n3.Inorder Traverse\n4.Postorder Traverse\n5.Delete\n0.Exit\nEnter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("\nEnter the element: ");
                                scanf("%d",&n);
                                root=bst_ins(root,n);
                                break;
                        case 2: preorder(root);
                                break;
			case 3: inorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: printf("\nEnter the element you want to delete: ");
				scanf("%d",&n);
				root=bst_del(root,n);
				break;
                        case 0: exit(0);
                }
        }
}
