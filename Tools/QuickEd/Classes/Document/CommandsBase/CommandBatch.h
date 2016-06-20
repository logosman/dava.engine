#pragma once

#include "Document/CommandsBase/Command.h"
#include "Base/BaseTypes.h"

class CommandBatch : public Command
{
public:
    CommandBatch(const DAVA::String& text);
    void Execute() override;
    void Undo() override;
    void Redo() override;

    void AddAndRedo(CommandPtr&& command);

    bool IsEmpty() const;

private:
    DAVA::Vector<CommandPtr> commands;
};
