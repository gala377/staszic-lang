#include <parser/nodes.hpp>

ast::Program::Program(std::vector<std::unique_ptr<Node>> nodes):
    nodes(std::move(nodes)) {}

void ast::Program::add_node(std::unique_ptr<Node> node) {
    nodes.emplace_back(std::move(node));
}