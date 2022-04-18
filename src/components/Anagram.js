import React, { useState, useEffect } from 'react';
import { Box, Card, CardActions, CardContent, Button, Typography, CardActionArea, CardHeader } from '@mui/material';
import axios from 'axios';


export default function Anagram({word}) {
    const [definition, setDefinition] = useState('');
    const [example, setExample] = useState('');
    const [partOfSpeech, setPartOfSpeech] = useState('');

    const href = `https://www.dictionary.com/browse/${word}`;

    useEffect(() => {
        const apiResponse = async() => {
            const object = await axios.get(`https://api.dictionaryapi.dev/api/v2/entries/en/${word}`);
            const data = object.data;
            const meaning = data[0]['meanings'][0];
            const partOfSpeech = meaning['partOfSpeech'];
            const definitions = meaning['definitions'];
            const definition = definitions[0]['definition'];
            const example = definitions[0]['example'];
            setDefinition(definition);
            setPartOfSpeech(partOfSpeech);
            if(example) {
                setExample(example);
            }
        };

        apiResponse();
    }, []);

    const openDictionaryWebsite = (event) => {
        window.open(href, '_blank');
    }

  return (
    <Card sx={{ width: 300, height: '100%', bgcolor: '#F9522F', textAlign: 'start' }}>
        <CardActionArea sx={{height: '100%'}} onClick={openDictionaryWebsite}>
            <CardContent>
                <Box sx={{ p: 2 }}>
                    <Typography variant="h5" component="div">
                        {word.toUpperCase()}
                    </Typography>
                    <Typography sx={{ mb: 1.5 }} color="text.secondary">
                        {partOfSpeech}
                    </Typography>
                    <Typography variant="body2" sx={{ mb: 1.5 }}>
                        {definition}
                    </Typography>
                    {/* <Typography variant='body2' color="text.secondary">
                        {example === '' && <>No Example Found</>}
                        {example !== '' && <>Example: "{example}"</>}
                    </Typography>  TODO: Find best way to display */}
                </Box>
            </CardContent>
        </CardActionArea>
    </Card>
  );
}
