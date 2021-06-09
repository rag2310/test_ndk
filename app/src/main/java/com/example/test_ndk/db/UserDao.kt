package com.example.test_ndk.db

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.Query
import com.example.test_ndk.model.User

@Dao
interface UserDao {
    @Query("SELECT NAME FROM User")
    fun getAll(): List<User>

    @Insert
    fun insertAll(vararg users: User)

    @Delete
    fun delete(user: User)
}