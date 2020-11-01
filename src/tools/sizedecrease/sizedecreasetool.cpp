// Copyright(c) 2017-2019 Alejandro Sirgo Rica & Contributors
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#include "sizedecreasetool.h"
#include <QPainter>

SizedecreaseTool::SizedecreaseTool(QObject* parent)
  : AbstractActionTool(parent)
{}

bool SizedecreaseTool::closeOnButtonPressed() const
{
    return false;
}

QIcon SizedecreaseTool::icon(const QColor& background, bool inEditor) const
{
    Q_UNUSED(inEditor);
    return QIcon(iconPath(background) + "minus.svg");
}
QString SizedecreaseTool::name() const
{
    return tr("Increase Tool Size");
}

ToolType SizedecreaseTool::nameID() const
{
    return ToolType::SIZEDECREASE;
}

QString SizedecreaseTool::description() const
{
    return tr("Decrease the size of the other tools");
}

CaptureTool* SizedecreaseTool::copy(QObject* parent)
{
    return new SizedecreaseTool(parent);
}

void SizedecreaseTool::pressed(const CaptureContext& context)
{
    Q_UNUSED(context);
    emit requestAction(REQ_DECREASE_TOOL_SIZE);
}
