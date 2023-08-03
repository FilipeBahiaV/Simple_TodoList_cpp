#include <string>

class TodoItem {
private:
    const int id;
    static int next_id;
    std::string text;
public:
    TodoItem() :id(next_id++), text("") {}

    void setText(std::string tex) {
        this->text = tex;
    }

    std::string getText() {
        return text;
    }

    int getId() {
        return id;
    }
};
int TodoItem::next_id = 0;