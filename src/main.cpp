#include <iostream>
#include <string>
#include <vector>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/dom/elements.hpp"

#include "numconv.h"

using namespace ftxui;

int main(void) {
	App screen = App::TerminalOutput();

	std::vector <std::string> in_bases  = {};
	std::vector <std::string> out_bases = {};
	in_bases.push_back("Input Base");
	out_bases.push_back("Output Base");

	for (int i=2; i<=36; i++) {
		in_bases.push_back(std::to_string(i));
		out_bases.push_back(std::to_string(i));
	}

	int inbase = 0, outbase = 0;
	std::string input, output;

	InputOption input_attr;
	input_attr.multiline = false;
	input_attr.on_enter = [&] {
		if (input.empty()) {
			return;
		}
		output = convert(input, inbase+1, outbase+1);
	};

	Component num_conv_ui = Container::Horizontal({
		Dropdown(&in_bases, &inbase),
		Dropdown(&out_bases, &outbase),

		Input(&input, "Number", input_attr) | border,
	});

	Component main_ui = Container::Vertical({
		Container::Horizontal({
			Button("Exit", screen.ExitLoopClosure(), ButtonOption::Ascii()) | color(Color::Red),
			Button("Convert", [&] {
				if (input.empty()) {
					return;
				}
				output = convert(input, inbase+1, outbase+1);
			}, ButtonOption::Ascii()) | color(Color::Green),
		}),
		num_conv_ui,
		Renderer([&] {return text(output);}) | border,
	});

	main_ui |= border;

	screen.Loop(main_ui);

	return 0;
}