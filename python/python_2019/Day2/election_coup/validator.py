def validator(age, voted):
    if age<18:
        return False
    elif voted<1 or voted>3:
        return False
    else:
        return True
