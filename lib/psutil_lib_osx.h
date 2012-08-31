//===========================================================================

#ifndef PSUTIL_LIB_OSX_H_
#define PSUTIL_LIB_OSX_H_

//===========================================================================

#define USE_MISALIGNED_MEMORY_ACCESS 1

#include <node.h>
#include <node_object_wrap.h>
#include <v8.h>

// using namespace v8;
using namespace node;

class PSUtilLib : public ObjectWrap {
  public:
    PSUtilLib();
    ~PSUtilLib() {}

    static void Initialize(v8::Handle<v8::Object> target);

    // Methods for data collection
    static v8::Handle<v8::Value> IoStat(const v8::Arguments& args);

    // Handles the uv calls
    static void Process(uv_work_t* work_req);
    // Called after work is done
    static void After(uv_work_t* work_req);

    // Constructor used for creating new BSON objects from C++
    static v8::Persistent<v8::FunctionTemplate> constructor_template;

  private:
    static v8::Handle<v8::Value> New(const v8::Arguments &args);
};

//===========================================================================

#endif  // PSUTIL_LIB_OSX_H_

//===========================================================================