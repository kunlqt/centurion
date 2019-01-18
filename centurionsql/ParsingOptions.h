//
//  ParsingOptions.h
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef ParsingOptions_h
#define ParsingOptions_h

namespace centurion {

    
class ParsingOptions
{

public:
	enum DecimalLiteralTreatment
	{
		AS_DOUBLE,
		AS_DECIMAL,
		REJECT
	};

	ParsingOptions() : decimalLiteralTreatment_(REJECT)
    {
        
    }
    
    ParsingOptions(DecimalLiteralTreatment decimalLiteralTreatment)
		: decimalLiteralTreatment_ (decimalLiteralTreatment) { }
    
    DecimalLiteralTreatment getDecimalLiteralTreatment() const
    {
        return decimalLiteralTreatment_;
    }

private:
    DecimalLiteralTreatment decimalLiteralTreatment_;
    
};

}

#endif /* ParsingOptions_h */
