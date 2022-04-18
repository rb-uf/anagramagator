import * as React from 'react';
import Box from '@mui/material/Box';
import Card from '@mui/material/Card';
import CardActions from '@mui/material/CardActions';
import CardContent from '@mui/material/CardContent';
import Button from '@mui/material/Button';
import Typography from '@mui/material/Typography';


export default function Anagram({word}) {
    const href = `https://www.dictionary.com/browse/${word}`;
  return (
    <Button href={href} target='_blank'>
        <Card sx={{ minWidth: 275, bgcolor: 'coral' }}>
        <CardContent>
            {/* <Typography sx={{ fontSize: 14 }} color="text.secondary" gutterBottom>
            Word of the Day
            </Typography> */}
            <Typography variant="h5" component="div">
            {word.toUpperCase()}
            </Typography>
            {/* <Typography sx={{ mb: 1.5 }} color="text.secondary">
            adjective
            </Typography> */}
            {/* <Typography variant="body2">
            well meaning and kindly.
            <br />
            {'"a benevolent smile"'}
            </Typography> */}
        </CardContent>
        <CardActions>
            {/* <Button size="small" href={href}>Learn More</Button> */}
        </CardActions>
        </Card>
    </Button>

  );
}
