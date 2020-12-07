#include <jni.h>
#include <string.h>
#include <string>

std::string ConvertJString(JNIEnv* env, jstring str)
{
    if ( !str ) std::string();

    const jsize len = env->GetStringUTFLength(str);
    const char* strChars = env->GetStringUTFChars(str, (jboolean *)0);

    std::string Result(strChars, len);

    env->ReleaseStringUTFChars(str, strChars);

    return Result;
}

extern "C"
JNIEXPORT jstring JNICALL Java_id_ac_ui_cs_mobileprogramming_helloworld_MainActivity_simplefun(JNIEnv* env, jobject, jstring text){
    std::string hello = ConvertJString( env, text );
    return env->NewStringUTF(hello.c_str());
}

