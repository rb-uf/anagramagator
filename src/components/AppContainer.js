import React from 'react';
import { Container, Box } from '@mui/material';
import AppHeader from './AppHeader';
import AppBody from './AppBody';

function AppContainer() {
  return (
    <Box>
        <Box sx={{ marginBottom: '10vh'}}>
            <AppHeader />
        </Box>
        <Container>
            <Box sx={{ display: 'flex', flexDirection: 'column', alignItems: 'center' }}>
                <AppBody />
            </Box>
        </Container>
    </Box>

  );
}

export default AppContainer;