template <typename T>
void MyVector<T>::extend(){
  if(n<alloc) return;
  alloc*=2;
  T* tmp = new T[alloc];
  for(size_t i=0;i<n;i++){
    tmp[i]=data[i];
  }
  delete[] data;
  data = tmp;
}

template <typename T>
MyVector<T>::MyVector() : data(new T[1]),n(0),alloc(1){}

template <typename T>
MyVector<T>::MyVector(int n) : data(new T[n],n(n),alloc(n){}

template <typename T>
MyVector<T>::MyVector(const MyVector tab&) : data(new T[tab.n]),n(tab.n),alloc(n){
  for(size_t i=0;i<n;i++){
    data[i]=tab.data[i];
  }
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector tab&){
  if(&tab!=*this){
    delete[] data;
    n = tab.n;
    alloc = n;
    data = new T[n];
    for(size_t i=0;i<n;i++){
      data[i]=tab.data[i];
    }
  }
  return *this;
}

template <typename T>
size_t MyVector::size() const{
  return n;
}

template <typename T>
T& MyVector<T>::at(int i){
  return data[i];
}

template <typename T>
int MyVector<T>::find(const T e&) const{
  for(size_t i=0;i<n;i++){
    if(data[i]==e){
      return i;
    }
  }
  return -1;
}

template <typename T>
void MyVector<T>::erase(size_t id){
  if(id>=0 && id<=n){
    for(size_t i=id;i<n-1;i++){
      data[i]=data[i+1];     
    }
    n--;
  }
}

template <typename T>
void MyVector<T>::push_back(T e){
  extend();
  data[n]=e;
  n++;
}

template <typename T>
MyVector<T>::~MyVector(){delete[] data;}

// Local Variables:
// mode: c++
// End:
