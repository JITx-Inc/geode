//#####################################################################
// Function wrap_method
//#####################################################################
#include <other/core/python/wrap_method.h>
namespace other {

PyObject* wrap_method_helper(PyTypeObject* type,const char* name,wrapperfunc wrapper,void* method) {
  // Allocate wrapperbase
  wrapperbase* base = (wrapperbase*)malloc(sizeof(wrapperbase));
  if (!base) throw std::bad_alloc();
  memset(base,0,sizeof(wrapperbase));

  // Fill in fields
  base->name = (char*)name;
  base->wrapper = wrapper;
  base->flags = 0; // no keyword args

  // Allocate wrapper
  PyObject* descr = PyDescr_NewWrapper(type,base,method);
  if (!descr) throw PythonError();
  return descr;
}

}
