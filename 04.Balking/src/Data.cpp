#include "Data.hpp"
Data::Data(std::string filename,std::string content){
        this->filename = filename;
        this->content = content;
        this->changed = true;
}
//データの内容を書き換える
void Data::change(std::string newContent) {
    std::lock_guard<std::mutex> lock(mtx);
    content = newContent;
    changed = true;
}
//データの内容が変更されていたらファイルに保存する
void Data::save(){
    std::lock_guard<std::mutex> lock(mtx);
    if (!changed) {
        return;
    }
    try{
        doSave();
    }catch(const char* e){
        throw e;
    }
    changed = false;
}
//データの内容を実際にファイルに保存する
void Data::doSave(){
    std::cout << std::this_thread::get_id() << " calls doSave, content = " << content << std::endl;
    try{
        std::ofstream ofs(filename);
        ofs << content <<std::endl;
        ofs.close();
    }catch(const char* e){
        throw e;
    }
}
