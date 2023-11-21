#include <stdio.h>

#define _iMaxLength 5000010

class TDeque
{
   public:
       TDeque(int * m_vNumbers, int iCount);
       void Push_Back(int iNumber);
       void Push_Front();
       void Pop_Back();
       int Get_Front();
       int Get_Back();

       int Not_Empty();
   protected:
       int m_iFront , m_iBack ;
       int * m_vNumbers;
       int iCount;

       int m_vValues[_iMaxLength];
   private:

};

int _vElements[_iMaxLength];

int Front, Back;
long long Sum;

//----------------------------------------
void TDeque::Push_Back(int iNumber)
{
   this->m_iBack++;
   this->m_vValues[this->m_iBack] = iNumber;
}
//----------------------------------------
void TDeque::Pop_Back()
{
   this->m_iBack--;
}
//----------------------------------------
TDeque::TDeque(int * m_vNumbers, int iCount)
{
   m_iFront=1;
   m_iBack=0;
   this->iCount=iCount;
   this->m_vNumbers=m_vNumbers;
}
//----------------------------------------
int TDeque::Get_Front()
{
   return this->m_vValues[this->m_iFront];
}
//----------------------------------------
int TDeque::Get_Back()
{
    return this->m_vValues[this->m_iBack];
}
//----------------------------------------
int TDeque::Not_Empty()
{
    return this->m_iFront <= this->m_iBack;
}
//----------------------------------------
void TDeque::Push_Front()
{
   this->m_iFront++;
}
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
 void ReadData(int * vElements, int * iLength, int *iCount)
{
   FILE * fIn = fopen("deque.in","r");
   fscanf(fIn,"%d %d ", iLength, iCount);

   for (int i = 1; i <= * iLength; i++)
      fscanf(fIn,"%d ", &vElements[i]);

   fclose(fIn);
}
 //----------------------------------------
int main()
{
    int iLength, iCount;
    long long lldSum=0;

    ReadData(_vElements,&iLength,&iCount);
    TDeque * objDeq = new TDeque(_vElements,iCount);

    for (int i = 1; i <= iLength; i++)
    {
        while (objDeq->Not_Empty() && _vElements[i] <= _vElements[ objDeq->Get_Back()])
            objDeq->Pop_Back();

        objDeq->Push_Back(i);

        if (objDeq->Get_Front() == i-iCount)
            objDeq->Push_Front();

        if (i >= iCount)
           lldSum += _vElements[objDeq->Get_Front()];
    }

    FILE * fOut = fopen("deque.out","w");

    fprintf(fOut,"%lld\n", lldSum);

    fclose(fOut);

    return 0;
}
