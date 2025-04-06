//
// Created by vladi on 07.04.2025.
//

#ifndef IDISPLAYABLE_H
#define IDISPLAYABLE_H

class IDisplayable {
public:
    virtual void displayInfo() const = 0;
    virtual ~IDisplayable() = default;
};

#endif // IDISPLAYABLE_H
