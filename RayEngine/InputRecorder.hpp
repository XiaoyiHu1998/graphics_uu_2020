#ifndef INPUT_RECORDER
#define INPUT_RECORDER


class InputRecorder{
private:
    std::vector<string> commands;
public:
    InputRecorder();
    std::vector<string> getCommandVector();
};

#endif //INPUT_RECORDER