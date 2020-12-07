#include <stdlib.h>
#include <stdio.h>

#include <types.h>
#include <tree.h>

HWThread hwThreadPool[48] = {
{ 0, 1, 0, 2 },
{ 0, 2, 0, 4 },
{ 0, 3, 0, 6 },
{ 0, 8, 0, 16 },
{ 0, 9, 0, 18 },
{ 0, 10 ,0, 20 },
{ 0, 1, 1, 34 },
{ 0, 2, 1, 36 },
{ 0, 3, 1, 38 },
{ 0, 8, 1, 48 },
{ 0, 9, 1, 50 },
{ 0, 10 ,1, 52 },
{ 0, 1, 2, 66 },
{ 0, 2, 2, 68 },
{ 0, 3, 2, 70 },
{ 0, 8, 2, 80 },
{ 0, 9, 2, 82 },
{ 0, 10 ,2, 84 },
{ 0, 1, 3, 98 },
{ 0, 2, 3, 100 },
{ 0, 3, 3, 102 },
{ 0, 8, 3, 112 },
{ 0, 9, 3, 114 },
{ 0, 10 ,3, 116 },
{ 0, 1, 4, 130 },
{ 0, 2, 4, 132 },
{ 0, 3, 4, 134 },
{ 0, 8, 4, 144 },
{ 0, 9, 4, 146 },
{ 0, 10 ,4, 148 },
{ 0, 1, 5, 162 },
{ 0, 2, 5, 164 },
{ 0, 3, 5, 166 },
{ 0, 8, 5, 176 },
{ 0, 9, 5, 178 },
{ 0, 10 ,5, 180 },
{ 0, 1, 6, 194 },
{ 0, 2, 6, 196 },
{ 0, 3, 6, 198 },
 {0 ,8 ,6 ,208 },
{ 0, 9, 6, 210 },
{ 0, 10 ,6, 212 },
{ 0, 1, 7, 226 },
{ 0, 2, 7, 228 },
{ 0, 3, 7, 230 },
{ 0, 8, 7, 240 },
{ 0, 9, 7, 242 },
{ 0, 10 ,7, 244 }};


int main (int argc, char** argv)
{ 
    int i;
    TreeNode* topologyTree;
    TreeNode* currentNode;
    tree_init(&topologyTree, 0);

    for (i=0; i<  48; i++)
    {
        /* Add node to Topology tree */
        if (!tree_nodeExists(topologyTree,
                    hwThreadPool[i].packageId))
        {
            tree_insertNode(topologyTree,
                    hwThreadPool[i].packageId);
        }
        currentNode = tree_getNode(topologyTree,
                hwThreadPool[i].packageId);

        if (!tree_nodeExists(currentNode, hwThreadPool[i].coreId))
        {
            tree_insertNode(currentNode, hwThreadPool[i].coreId);
        }
        currentNode = tree_getNode(currentNode, hwThreadPool[i].coreId);

        if (!tree_nodeExists(currentNode, i))
        {
            tree_insertNode(currentNode, i);
        }
    }

    tree_print(topologyTree);

    printf("\nNumber Of Sockets %d \n", tree_countChildren(topologyTree));
    currentNode = tree_getChildNode(topologyTree);
    printf("NumberOfCores %d \n", tree_countChildren(currentNode));
    currentNode = tree_getChildNode(currentNode);
    printf("Number Of Threads %d \n", tree_countChildren(currentNode));

}
