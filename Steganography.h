/** 
* @file Steganography.h
* @author Власов Н.С.
* @version 1.0
* @date 15.20.2020
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля Steganography
*/
#pragma once
#include <string>
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <codecvt>
using namespace std;
/** 
* @brief Программа для стеганографического преобрзования
*/
class Steganography {
    
private:
    string file_container;
    string file_message;
    string file_new;
public:
    int concealment(string file_container, string file_message);
    int extraction(string file_container);
};

/** @brief Класс обработки ошибок error_proj
* @details Выводит сообщения об ошибках
*/
class error_proj: public std::invalid_argument
{
public:
	explicit error_proj (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit error_proj (const char* what_arg):
		std::invalid_argument(what_arg) {}
};