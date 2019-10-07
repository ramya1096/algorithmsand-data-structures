#include<stddef.h>
#include<assert.h>
#include<stdio.h>
#include<stdint.h>
#include "bst.h"

BST bst_new()
{
    BST tree={NULL,0};
    return tree;
}

static TreeNode* _make_new_node(int32_t element)
{
   TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
   node->data=element;
   node->left=NULL;
   node->right=NULL;
   return node;
}

uint32_t bst_count(BST *tree)
{
    assert(tree!=NULL);
    return tree->mass;
}

BST* bst_add_node(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    TreeNode *cur,*parent;
    cur=parent=tree->root;
    while(cur!=NULL && cur->data!=element){
        parent=cur;
        if(element<cur->data){
            cur=cur->left;
        }
        else if(element>cur->data){
        cur=cur->right;
        }
    }
    if(cur==NULL){
        TreeNode *tnode=_make_new_node(element);
        if(parent==NULL){
            tree->root=tnode;
        }
        else if(element<parent->data){
        parent->left=tnode;
        }
        else if(element>parent->data){
            parent->right=tnode;
        }
        ++tree->mass;
        }
        return tree;
}



uint32_t bst_lookup(BST *tree,int32_t key)
{
    assert(tree!=NULL);
    TreeNode *cur=tree->root;
    while(cur!=NULL && cur->data!=key){
        if(key<cur->data){
            cur=cur->left;
        }
        else if(key>cur->data){
            cur=cur->right;
        }
    }
    return(cur!=NULL);
}

BST* bst_delete(BST *tree,int32_t element)
{
    assert(tree!=NULL);
    tree->root=_delete_(tree,tree->root,element);
    return tree;
}

static TreeNode* _delete_(BST *tree,TreeNode *node,int32_t key)
{
   TreeNode *temp;
   if(node==NULL)
   {
       return node;
   }
    else if(key<node->data)
    {
        node->left=_delete_(tree_node->left,key);
    }
    else if(key>node->data)
    {
         node->right=_delete_(tree_node->right,key);
    }
    else {
        temp=node;
        if(node->right==NULL)
        {
            node=node->left;
        }
        else{
            node=node->right;
        }
        free(temp);
        --tree->mass;
    }
    return node;
}

/*static TreeNode* _find_Min(TreeNode *node)
{
  if(node->left==NULL){
    return node;
    }
    else(return(_find_Min_(root->left)))
}
void bst_inorder(BST *tree)
{
	assert(tree->root=NULL);
	_inorder_(tree->root);
}

static void _inorder_(TreeNode *node)
{
if(node)
{
_inorder_(node->left);
printf("%d\t",node->data);
_inorder_(node->right);
}
}

static void _preorder_(TreeNode *node)
{
if(node)
{
printf("%d\t",node->data);
_preorder_(node->left);
_preorder_(node->right);
}
}

void bst_preorder(BST *tree)
{
	assert(tree->root!=NULL);
	_preorder_(tree->root);
}

static void _postorder_(TreeNode *node)
{
if(node)
{
_postorder_(node->left);
_postorder_(node->right);
printf("%d\t",node->data);
}
}

void bst_postorder(BST *tree)
{
	assert(tree->root!=NULL);
	_postorder_(tree->root);
	printf("\n");
}

static int32_t max_height(TreeNode *node)
{
int32_t left_height=0;
int32_t right_height = 0;

if(node == NULL)
{
return 0;
}
else
{

if(node->left!=NULL){
left_height = max_height(node->left);
}
if(node->right!=NULL){
right_height = max_height(node->right);

}
if(left_height>right_height)
{
return left_height+1;
}
else
{
return right_height+1;
}
}
}


int32_t tree_height(BST *tree)
{
assert(tree->root!=NULL);

int32_t max = max_height(tree->root);

}

static void _ascending_(TreeNode *node)
{
if(node)
{
_ascending_(node->left);
printf("%d\t",node->data);
_ascending_(node->right);
}
}

void tree_ascending(BST*tree)
{
	assert(tree->root!=NULL);
	_ascending_(tree->root);
}

static void _descending_(TreeNode *node)
{
if(node)
{
_descending_(node->right);
printf("%d\t",node->data);
_descending_(node->left);
}
}

void tree_descending(BST*tree)
{
	assert(tree->root!=NULL);
	_descending_(tree->root);
}*/
