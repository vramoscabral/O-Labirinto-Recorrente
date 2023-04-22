#include "mat.hpp"
int Matriz::vida=10;
int Matriz::abc=0;
int Matriz::vida2=10;
int Matriz::itens2=0;
int Matriz::casas=0;
int Matriz::itens=0;
int Matriz::ntimes=1;
int Matriz::perigo=0;

Matriz::Matriz()
{}

int Matriz::sabc()
{
  return abc;
}

int Matriz::seecasas()
{
  return casas;
}

int Matriz::seevida()
{
  return vida;
}

int Matriz::seeperigo()
{
  return perigo;
}

int Matriz::seeitens()
{
  return itens;
}

void Matriz::Readfile()
{
  ifstream matt;
  int a, n=1, size=Tam(), i, j;

  matt.open("dataset/input.data");
  matt >> a >> a >> nummat;

  for (int c=0; c<nummat; c++)
  {
    char **mtrx=new char*[size];
    for (i=0; i<size; i++)
      mtrx[i]=new char[size];

    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        matt >> mtrx[i][j];
      }
    }

    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        cout << mtrx[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

    ofstream arq;
    
    arq.open("dataset/mat" + to_string(n) + ".data");

    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        arq << mtrx[i][j] << " ";
      }
      arq << endl;
    }
    n++;

    arq.close();

    for (i=0; i<size; i++)
      delete[] mtrx[i];
    delete[] mtrx;
  }

  matt.close();
}

void Matriz::remove()
{
  ifstream frst;
  int a, n=1, size=Tam(), i;

  frst.open("dataset/input.data");
  frst >> a >> a >> nummat;
  frst.close();
  
  for (int c=0; c<nummat; c++)
  {
    string filename = "dataset/mat" + to_string(n) + ".data";

    std::remove(filename.c_str());
    n++;
  }
}

void Matriz::Output()
{
  ifstream frst;
  ofstream matt;
  int a, n=1, size=Tam(), i, j;

  frst.open("dataset/input.data");
  frst >> a >> a >> nummat;
  frst.close();

  matt.open("dataset/output.data");
  matt << a << " " << a << " " << nummat << endl;
  
  for (int c=0; c<nummat; c++)
  {
    char **mtrx=new char*[size];
    for (i=0; i<size; i++)
      mtrx[i]=new char[size];

    ifstream arq;
    
    arq.open("dataset/mat" + to_string(n) + ".data");

    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        arq >> mtrx[i][j];
      }
    }
    n++;

    arq.close();

    for (i=0; i<a; i++)
    {
      for (j=0; j<a; j++)
      {
        matt << mtrx[i][j] << " ";
      }
      matt << endl;
    }
    matt << endl;

    for (i=0; i<size; i++)
      delete[] mtrx[i];
    delete[] mtrx;
  }

  matt.close();
}

int Matriz::NotVisited()
{
  ifstream arq, matt;
  char e;
  int a=0, n=1, size=Tam(), i, j;

  matt.open("dataset/input.data");
  matt >> a >> a >> nummat;
  
  for (int c=0; c<nummat; c++)
  {
    int **mtrx=new int*[size];
      for (i=0; i<size; i++)
        mtrx[i]=new int[size];

    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
        matt >> e;
        if (e=='*')
          mtrx[i][j] = -1;
        else if (e=='#')
          mtrx[i][j] = -2;
        else
          mtrx[i][j] = e - '0';
      }
    }
    
    arq.open("dataset/mat" + to_string(n) + ".data");
  
    int **mtf=new int*[size];
      for (i=0; i<size; i++)
        mtf[i]=new int[size];
  
    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
        arq >> e;
        if (e=='*')
          mtf[i][j] = -1;
        else if (e=='#')
          mtf[i][j] = -2;
        else
          mtf[i][j] = e - '0';
      }
    }
    n++;

    arq.close();

    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
        if (mtrx[i][j]==mtf[i][j] && mtrx[i][j]>0)
          a++;
      }
    }

    for (i=0; i<size; i++)
      delete[] mtrx[i];
    delete[] mtrx;
    
    for (i=0; i<size; i++)
      delete[] mtf[i];
    delete[] mtf;
  }

  matt.close();
  return a;
}

int Matriz::Tam()
{
  ifstream tam;

  tam.open("dataset/input.data");
  int size;

  tam >> size >> size;

  tam.close();

  return size;
}

int Matriz::Quant()
{
  ifstream tam;

  tam.open("dataset/input.data");
  int size;

  tam >> size >> size >> size;

  tam.close();

  return size;
}

int Matriz::WalkMatrix(int **mtrx, int im, int jm, int rsize, int n)
{
  unsigned short int yy=1, move;
  int fn=n;

  while (yy==1 && vida!=0)
  {
    move=1+rand()%8;

    if (vida<10 && itens>0 && itens%4==0)
      vida++;

    if (itens2==itens && n==1 && ntimes>Quant())
    {
      abc=2;
      break;
    }
      
    cout << "vidas: " << vida << ", Matriz " << n << endl;
    cout << "casa " << im << " e " << jm << ", movimento: " << move;
    cout << ", itens: " << itens << endl;
    switch(move)
    {
      case 1:
        if (im>0 && jm<rsize)
        {
          if (mtrx[im-1][jm+1]>=0 && jm+1==rsize || mtrx[im-1][jm+1]>=0 && im-1==0)
          {
            if (mtrx[im-1][jm+1]>0)
            {
              mtrx[im-1][jm+1] -= 1;
              itens++;
            }
            casas++;
            im--;
            jm++;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im-1][jm+1]>0)
          {
            mtrx[im-1][jm+1] -= 1;
            casas++;
            im--;
            jm++;
            itens++;
          }
          else if (mtrx[im-1][jm+1]==0)
          {
            casas++;
            im--;
            jm++;
          }
          else if (mtrx[im-1][jm+1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im--;
            jm++;
          }
        }
        break;
      case 2:
        if (jm<rsize)
        {
          if (mtrx[im][jm+1]>=0 && jm+1==rsize)
          {
            if (mtrx[im][jm+1]>0)
            {
              mtrx[im][jm+1] -= 1;
              itens++;
            }
            casas++;
            jm++;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im][jm+1]>0)
          {
            mtrx[im][jm+1] -= 1;
            casas++;
            jm++;
            itens++;
          }
          else if (mtrx[im][jm+1]==0)
          {
            casas++;
            jm++;
          }
          else if (mtrx[im][jm+1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            jm++;
          }
        }
        break;
      case 3:
        if (im<rsize && jm<rsize)
        {
          if (mtrx[im+1][jm+1]>=0 && jm+1==rsize || mtrx[im+1][jm+1]>=0 && im+1==rsize)
          {
            if (mtrx[im+1][jm+1]>0)
            {
              mtrx[im+1][jm+1] -= 1;
              itens++;
            }
            casas++;
            im++;
            jm++;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im+1][jm+1]>0)
          {
            mtrx[im+1][jm+1] -= 1;
            casas++;
            im++;
            jm++;
            itens++;
          }
          else if (mtrx[im+1][jm+1]==0)
          {
            casas++;
            im++;
            jm++;
          }
          else if (mtrx[im+1][jm+1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im++;
            jm++;
          }
        }
        break;
      case 4:
        if (im<rsize)
        {
          if (mtrx[im+1][jm]>=0 && im+1==rsize)
          {
            if (mtrx[im+1][jm]>0)
            {
              mtrx[im+1][jm] -= 1;
              itens++;
            }
            casas++;
            im++;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im+1][jm]>0)
          {
            mtrx[im+1][jm] -= 1;
            casas++;
            im++;
            itens++;
          }
          else if (mtrx[im+1][jm]==0)
          {
            casas++;
            im++;
          }
          else if (mtrx[im+1][jm]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im++;
          }
        }
        break;
      case 5:
        if (im<rsize && jm>0)
        {
          if (mtrx[im+1][jm-1]>=0 && im+1==rsize || mtrx[im+1][jm-1]>=0 && jm-1==0)
          {
            if (mtrx[im+1][jm-1]>0)
            {
              mtrx[im+1][jm-1] -= 1;
              itens++;
            }
            casas++;
            im++;
            jm--;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im+1][jm-1]>0)
          {
            mtrx[im+1][jm-1] -= 1;
            casas++;
            im++;
            jm--;
            itens++;
          }
          else if (mtrx[im+1][jm-1]==0)
          {
            casas++;
            im++;
            jm--;
          }
          else if (mtrx[im+1][jm-1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im++;
            jm--;
          }
        }
        break;
      case 6:
        if (jm>0)
        {
          if (mtrx[im][jm-1]>=0 && jm-1==0)
          {
            if (mtrx[im][jm-1]>0)
            {
              mtrx[im][jm-1] -= 1;
              itens++;
            }
            casas++;
            jm--;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im][jm-1]>0)
          {
            mtrx[im][jm-1] -= 1;
            casas++;
            jm--;
            itens++;
          }
          else if (mtrx[im][jm-1]==0)
          {
            casas++;
            jm--;
          }
          else if (mtrx[im][jm-1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            jm--;
          }
        }
        break;
      case 7:
        if (im>0 && jm>0)
        {
          if (mtrx[im-1][jm-1]>=0 && im-1==0 || mtrx[im-1][jm-1]>=0 && jm-1==0)
          {
            if (mtrx[im-1][jm-1]>0)
            {
              mtrx[im-1][jm-1] -= 1;
              itens++;
            }
            casas++;
            im--;
            jm--;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im-1][jm-1]>0)
          {
            mtrx[im-1][jm-1] -= 1;
            casas++;
            im--;
            jm--;
            itens++;
          }
          else if (mtrx[im-1][jm-1]==0)
          {
            casas++;
            im--;
            jm--;
          }
          else if (mtrx[im-1][jm-1]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im--;
            jm--;
          }
        }
        break;
      case 8:
        if (im>0)
        {
          if (mtrx[im-1][jm]>=0 && im-1==0)
          {
            if (mtrx[im-1][jm]>0)
            {
              mtrx[im-1][jm] -= 1;
              itens++;
            }
            casas++;
            im--;
            if (n==nummat)
              n=1;
            else
              n++;
            yy=0;
          }
          else if (mtrx[im-1][jm]>0)
          {
            mtrx[im-1][jm] -= 1;
            casas++;
            im--;
            itens++;
          }
          else if (mtrx[im-1][jm]==0)
          {
            casas++;
            im--;
          }
          else if (mtrx[im-1][jm]==-1)
          {
            casas++;
            vida--;
            perigo++;
            im--;
          }
        }
        break;
    }
    cout << "\ndepois do movimento\n\n";
    for (int a=0; a<rsize+1; a++)
    {
      for (int b=0; b<rsize+1; b++)
      {
        cout << mtrx[a][b] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  ofstream arq("dataset/mat" + to_string(fn) + ".data", ofstream::out);

  for (int i=0; i<rsize+1; i++)
  {
    for (int j=0; j<rsize+1; j++)
    {
      if (mtrx[i][j]==-1)
        arq << "* ";
      else if (mtrx[i][j]==-2)
        arq << "# ";
      else
        arq << mtrx[i][j] << " ";
    }
    arq << endl;
  }

  vida2=vida;
  if (fn==1)
    itens2=itens;
  ntimes++;

  arq.close();
  return n;
}

void Matriz::OpenMatrix()
{
  ifstream mat;
  int n=1, size=Tam(), i, j, im, jm, move;
  char e;
  unsigned short int zz=1, yy;
  cout << endl;
  int rsize=size-1;

  while (zz==1)
  {
    mat.open("dataset/mat" + to_string(n) + ".data");
  
    int **mtrx=new int*[size];
      for (i=0; i<size; i++)
        mtrx[i]=new int[size];
  
    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
        mat >> e;
        if (e=='*')
          mtrx[i][j] = -1;
        else if (e=='#')
          mtrx[i][j] = -2;
        else
          mtrx[i][j] = e - '0';
      }
    }

    if (casas==0)
      cout << "\nMatriz inicial\n\n";
    else
      cout << "\nPulo pra matriz " << n << "\n\n";
    
    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
        cout << mtrx[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    im=1+rand()%+(rsize-1);
    jm=1+rand()%+(rsize-1);

    n=WalkMatrix(mtrx,im,jm,rsize,n);

    for (i=0; i<size; i++)
      delete[] mtrx[i];
    delete[] mtrx;
    
    if (vida==0)
    {
      zz=0;
      abc=1;
    }
    if (abc==2)
      zz=0;
    mat.close();
  }
}
