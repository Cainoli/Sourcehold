#pragma once

#include <cinttypes>
#include <string>
#include <vector>

#include "Parsers/Gm1File.h"

#include "Events/Event.h"
#include "Events/Mouse.h"

#include "GUI/Widgets/Widget.h"

namespace Sourcehold {
    namespace GUI {
        struct Column {
            std::wstring name;
            std::vector<std::wstring> rows;
        };

        using namespace Events;

        class Table : protected EventConsumer<Mouse> {
        public:
            Table() = default;
            Table(uint32_t rows, uint32_t columns);
            ~Table() = default;

            void Create(uint32_t rows, uint32_t columns);
            void Destroy();
            void Render(int x, int y, int w);

            void SetNumRows(uint32_t n);
            void SetNumCols(uint32_t n);
            void SetColName(uint32_t n, const std::wstring& name);
            void SetText(uint32_t row, uint32_t col, const std::wstring& text);

            inline int GetSelected() { return selected; }
            inline int GetHighlight() { return highlight; }

            inline void Scrollable(bool b) { scrollbar = true; }
            inline void RenderNames(bool b) { renderNames = b; }
        protected:
            void onEventReceive(Mouse &mouse) override;

            std::vector<Column> cols;
            bool scrollbar = true;
            bool renderNames = true;
            uint32_t numRows = 0;
            int highlight = -1, selected = -1;
        };
    }
}
