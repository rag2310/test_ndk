//
// Created by rodolfo_pc on 8/6/2021.
//
#include <jni.h>
#include <string>
#include "Calculator.h"
#include "db/sqlite3.h"
#include <android/log.h>

#define LOG_TAG "libgl2jni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
/*
int db(const char *path) {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    rc = sqlite3_open(path, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cant't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_open_v2(path, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
        return -1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    *//* Create SQL statement *//*
    sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

    *//* Execute SQL statement *//*
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}*/

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_test_1ndk_MainActivity_initDb(JNIEnv *env, jobject, jstring path) {

    sqlite3 *db;
    sqlite3_stmt *stmt;

    const char *database = env->GetStringUTFChars(path, 0);

    char *zErrMsg = 0;
    int rc;
    const char *sql;

    if (sqlite3_open_v2(database, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) ==
        SQLITE_OK) {
        LOGE("database open!!");

        sql = "CREATE TABLE COMPANY("
          "ID INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "AGE            INT     NOT NULL,"
          "ADDRESS        CHAR(50),"
          "SALARY         REAL );";

        rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);

        if (rc != SQLITE_OK) {
            LOGE("SQL ERROR:%s", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            LOGE("CREATE Operation done successfully\n");
        }

        //rc = sqlite3_exec(db, insert_sql, NULL, NULL, &zErrMsg);

        if (rc != SQLITE_OK) {
            LOGE("SQL ERROR:%s", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            LOGE("INSERT Operation done successfully\n");
        }

        /*rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, NULL);

        if( rc != SQLITE_OK ) {
            LOGE("SQL ERROR:%s", zErrMsg);
            sqlite3_free(zErrMsg);
        } else {
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                const unsigned char * aaa           = sqlite3_column_text (stmt, 0);
                const unsigned char * bbb           = sqlite3_column_text (stmt, 1);

                LOGE("%s, %s", aaa, bbb);
            }

            if (rc != SQLITE_DONE) {
                LOGE("error: %s", sqlite3_errmsg(db));
            }

            LOGE("SELECT Operation done successfully\n");

            sqlite3_finalize(stmt);
        }*/

    } else {
        LOGE("database can not open!! : %s", sqlite3_errmsg(db));
    }

    sqlite3_close(db);

    return 0;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_test_1ndk_MainActivity_helloWorld(JNIEnv *env, jobject thiz) {
    std::string hello = "Calculator C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_test_1ndk_MainActivity_sum(JNIEnv *env, jobject thiz, jint x, jint y) {
    return Calculator::sum(x, y);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_test_1ndk_MainActivity_sub(JNIEnv *env, jobject thiz, jint x, jint y) {
    return Calculator::sub(x, y);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_test_1ndk_MainActivity_mult(JNIEnv *env, jobject thiz, jint x, jint y) {
    return Calculator::mult(x, y);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_test_1ndk_MainActivity_div(JNIEnv *env, jobject thiz, jint x, jint y) {
    return Calculator::div(x, y);
}
