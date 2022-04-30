typedef int itype;


typedef struct nodetagDQ{
            itype ITEM;
            struct nodetagDQ *LINK;

}nodeDQ;


struct tDeque {
         nodeDQ *FRONT;
         nodeDQ *REAR;
         int sum;
};          