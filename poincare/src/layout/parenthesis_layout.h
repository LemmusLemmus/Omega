#ifndef POINCARE_PARENTHESIS_LAYOUT_H
#define POINCARE_PARENTHESIS_LAYOUT_H

#include <poincare/static_layout_hierarchy.h>
#include <poincare/layout_engine.h>

namespace Poincare {

class ParenthesisLayout : public StaticLayoutHierarchy<3> {
public:
  constexpr static KDCoordinate k_parenthesisCurveWidth = 5;
  constexpr static KDCoordinate k_parenthesisCurveHeight = 7;
  ParenthesisLayout(ExpressionLayout * operand, bool cloneOperands);
  ExpressionLayout * clone() const override;
  bool moveLeft(ExpressionLayoutCursor * cursor) override;
  bool moveRight(ExpressionLayoutCursor * cursor) override;
  int writeTextInBuffer(char * buffer, int bufferSize) const override {
    return LayoutEngine::writeInfixExpressionLayoutTextInBuffer(this, buffer, bufferSize, "");
  }
protected:
  void render(KDContext * ctx, KDPoint p, KDColor expressionColor, KDColor backgroundColor) override {
  };
  KDSize computeSize() override;
  void computeBaseline() override;
  KDPoint positionOfChild(ExpressionLayout * child) override;
private:
  constexpr static KDCoordinate k_externWidthMargin = 1;
  constexpr static KDCoordinate k_externHeightMargin = 2;
  constexpr static KDCoordinate k_widthMargin = 5;
  constexpr static KDCoordinate k_lineThickness = 1;
  ExpressionLayout * operandLayout();
  ExpressionLayout * leftParenthesisLayout();
  ExpressionLayout * rightParenthesisLayout();
};

}

#endif
