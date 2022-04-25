import './App.css';
import { render } from "react-dom";
import {
  BrowserRouter,
  Routes,
  Route,
} from "react-router-dom";
import Index from './components/Index';
import Party from './components/Party';
import About from './components/About';

function App() {
  return (
   < div className="Politikisto">

     {/* <Index /> */}
    
     <Routes>
     <Route path="" element={ <Index />} /> 
       <Route path="about" element={<About />} />
       <Route path="party" element={<Party />} />
     </Routes>
     </div>
  );
}

export default App;
