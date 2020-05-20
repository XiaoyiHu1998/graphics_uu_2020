#include "InputRecorder.hpp"

InputRecorder::InputRecorder(){

}

std::vector<string>* InputRecorder::getCommandVector(){
    return &commands;
}