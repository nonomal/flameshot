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

#include "sizeincreasetool.h"
#include <QPainter>

SizeincreaseTool::SizeincreaseTool(QObject* parent)
  : AbstractActionTool(parent)
{}

bool SizeincreaseTool::closeOnButtonPressed() const
{
    return false;
}

QIcon SizeincreaseTool::icon(const QColor& background, bool inEditor) const
{
    Q_UNUSED(inEditor);
    return QIcon(iconPath(background) + "plus.svg");
}
QString SizeincreaseTool::name() const
{
    return tr("Increase Tool Size");
}

ToolType SizeincreaseTool::nameID() const
{
    return ToolType::SIZEINCREASE;
}

QString SizeincreaseTool::description() const
{
    return tr("Increase the size of the other tools");
}

CaptureTool* SizeincreaseTool::copy(QObject* parent)
{
    return new SizeincreaseTool(parent);
}

void SizeincreaseTool::pressed(const CaptureContext& context)
{
    Q_UNUSED(context);
    emit requestAction(REQ_INCREMENT_CIRCLE_COUNT);
}
