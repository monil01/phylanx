from __future__ import absolute_import
from __future__ import annotations

__license__ = """
Copyright (c) 2021 R. Tohid (@rtohid)

Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
"""

import ast

from abc import ABC, abstractmethod

from physl.control import Task


class Transpiler(ABC, ast.NodeVisitor):
    def __init__(self, task: Task) -> None:
        self.task = task
        self.fn = task.fn

        py_ast = task.py_ast
        self.transpile(py_ast)

    @abstractmethod
    def transpile(self, node):
        pass

    @abstractmethod
    def __str__(self) -> str:
        ...

    def walk(self, node):
        target = self.visit(node)
        if target is None:
            raise NotImplementedError(
                f"Transformation rule for {node} is not implemented.")
        else:
            return target