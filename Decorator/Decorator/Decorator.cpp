#include <iostream>
using namespace std;

class TextEditor {

	string text;

public:
	TextEditor() {
	}


	TextEditor(TextEditor* textEditor) {
		this->text = textEditor->getText();
	}

	string getText() {
		return text;
	}

	void setText(string text) {
		this->text = text;
	}
};

class SimpleTextEditor : public TextEditor {
public:
	SimpleTextEditor() : TextEditor() {
		setText("base text");
	}

	SimpleTextEditor(TextEditor* textEditor) : TextEditor(textEditor) {
		setText(textEditor->getText() + " base text");
	}


};

class SpellChecker : public TextEditor {
public:
	SpellChecker() : TextEditor() {}
	SpellChecker(TextEditor* textEditor) : TextEditor(textEditor) {
		setText(textEditor->getText() + " spell text");
	}
};

class AutoSave : public TextEditor {
public:
	AutoSave() : TextEditor() {}
	AutoSave(TextEditor* textEditor) : TextEditor(textEditor) {
		setText(textEditor->getText() + " auto save text");
	}
};

int main() {

	TextEditor* editor = new SimpleTextEditor();


	editor = new SpellChecker(editor);
	editor = new AutoSave(editor);
	editor = new SpellChecker(editor);
	editor = new SimpleTextEditor(editor);

	cout << editor->getText();
}