#ifndef INPUT_RECORDER_HPP
#define INPUT_RECORDER_HPP


class InputRecorder{
private:
    std::vector<string> commands;
public:
    InputRecorder();
    std::vector<string> getCommandVector();
};

#endif //INPUT_RECORDER_HPP