//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   C O N V O L U T I O N A L   L A Y E R   T E S T   C L A S S
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#include "convolutional_layer_test.h"

ConvolutionalLayerTest::ConvolutionalLayerTest() : UnitTesting()
{
}


ConvolutionalLayerTest::~ConvolutionalLayerTest()
{
}


void ConvolutionalLayerTest::test_set()
{
    cout << "test_set\n";
}


void ConvolutionalLayerTest::test_eigen_convolution()
{
    cout << "test_eigen_convolution\n";

    // Convolution 2D, 1 channel
    Tensor<type, 2> input(3, 3);
    Tensor<type, 2> kernel(2, 2);
    Tensor<type, 2> output;
    input.setRandom();
    kernel.setRandom();

    Eigen::array<ptrdiff_t, 2> dims = {0, 1};

    output = input.convolve(kernel, dims);

    assert_true(output.dimension(0) == 2, LOG);
    assert_true(output.dimension(1) == 2, LOG);

    // Convolution 2D, 3 channels
    Tensor<type, 3> input_2(5, 5, 3);
    Tensor<type, 3> kernel_2(2, 2, 3);
    Tensor<type, 3> output_2;
    input_2.setRandom();
    kernel_2.setRandom();

    Eigen::array<ptrdiff_t, 3> dims_2 = {0, 1, 2};

    output_2 = input_2.convolve(kernel_2, dims_2);

    assert_true(output_2.dimension(0) == 4, LOG);
    assert_true(output_2.dimension(1) == 4, LOG);
    assert_true(output_2.dimension(2) == 1, LOG);


    // Convolution 2D, 3 channels, multiple images, 1 kernel
    Tensor<type, 4> input_3(10, 3, 5, 5);
    Tensor<type, 3> kernel_3(3, 2, 2);
    Tensor<type, 4> output_3;
    input_3.setConstant(type(1));
    input_3.chip(1, 0).setConstant(type(2));
    input_3.chip(2, 0).setConstant(type(3));

    kernel_3.setConstant(type(1.0/12.0));

    Eigen::array<ptrdiff_t, 3> dims_3 = {1, 2, 3};

    output_3 = input_3.convolve(kernel_3, dims_3);

    assert_true(output_3.dimension(0) == 10, LOG);
    assert_true(output_3.dimension(1) == 1, LOG);
    assert_true(output_3.dimension(2) == 4, LOG);
    assert_true(output_3.dimension(3) == 4, LOG);

    assert_true(abs(output_3(0, 0, 0, 0) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 0, 1) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 0, 2) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 0, 3) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 1, 0) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 1, 1) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 1, 2) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 1, 3) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 2, 0) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 2, 1) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 2, 2) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 2, 3) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 3, 0) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 3, 1) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 3, 2) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(0, 0, 3, 3) - type(1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 0, 0) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 0, 1) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 0, 2) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 0, 3) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 1, 0) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 1, 1) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 1, 2) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 1, 3) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 2, 0) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 2, 1) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 2, 2) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 2, 3) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 3, 0) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 3, 1) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 3, 2) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(1, 0, 3, 3) - type(2)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 0, 0) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 0, 1) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 0, 2) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 0, 3) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 1, 0) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 1, 1) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 1, 2) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 1, 3) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 2, 0) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 2, 1) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 2, 2) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 2, 3) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 3, 0) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 3, 1) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 3, 2) - type(3)) < type(NUMERIC_LIMITS_MIN) &&
                abs(output_3(2, 0, 3, 3) - type(3)) <= type(NUMERIC_LIMITS_MIN), LOG);

}

void ConvolutionalLayerTest::test_eigen_convolution_3d()
{
    cout << "test_eigen_3d_convolution\n";

    // Convolution 3D, 2 channels

    Tensor<type, 3> input(3, 3, 2);
    Tensor<type, 3> kernel(2, 2, 2);
    Tensor<type, 3> output(2, 2, 1);

    for(int i=0;i<3*3*2;i++) *(input.data() + i) = i;
    for(int i=0;i<2*2*2;i++) *(kernel.data() + i) = i+1;

    Eigen::array<ptrdiff_t, 3> dims = {0,1,2};

    output = input.convolve(kernel, dims);

    assert_true(fabs(output(0,0,0) - 320)<type(NUMERIC_LIMITS_MIN), LOG);
    assert_true(fabs(output(1,0,0) - 356)<type(NUMERIC_LIMITS_MIN), LOG);
    assert_true(fabs(output(0,1,0) - 428)<type(NUMERIC_LIMITS_MIN), LOG);
    assert_true(fabs(output(1,1,0) - 464)<type(NUMERIC_LIMITS_MIN), LOG);
}


void ConvolutionalLayerTest::test_read_bmp()
{
    DataSet data_set;

    data_set.set_data_file_name("C:/Users/alvaromartin/Documents/Dataset for read_bmp()/");

    data_set.read_bmp();

    data_set.print();

    Tensor<type, 2> data = data_set.get_data();

//    cout<< "Printing data: " << endl;
//    cout<<data<<endl;
}


void ConvolutionalLayerTest::test_constructor()
{
    cout << "test_constructor\n";

    Tensor<Index, 1> new_inputs_dimensions(4);
    Tensor<Index, 1> new_kernels_dimensions(4);

    new_inputs_dimensions.setValues({23, 64, 3, 1});
    new_kernels_dimensions.setValues({3, 2, 1, 1});

    ConvolutionalLayer convolutional_layer(new_inputs_dimensions, new_kernels_dimensions);

    assert_true(convolutional_layer.get_inputs_channels_number() == 3 &&
                convolutional_layer.get_inputs_rows_number() == 23 &&
                convolutional_layer.get_inputs_columns_number() == 64, LOG);
}


void ConvolutionalLayerTest::test_destructor()
{
   cout << "test_destructor\n";
}


void ConvolutionalLayerTest::test_set_parameters()
{
    cout << "test_set_parameters\n";
/*
    Tensor<type, 4> new_synaptic_weights(2, 2, 2, 2);
    Tensor<type, 1> new_biases(2);
    Tensor<type, 1> parameters(18);

    convolutional_layer.set_biases(new_biases);
    convolutional_layer.set_synaptic_weights(new_synaptic_weights);

    new_synaptic_weights(0,0,0,0) = type(1);
    new_synaptic_weights(0,0,0,1) = type(2);
    new_synaptic_weights(0,0,1,0) = type(3);
    new_synaptic_weights(0,0,1,1) = type(4);
    new_synaptic_weights(0,1,0,0) = type(5);
    new_synaptic_weights(0,1,0,1) = type(6);
    new_synaptic_weights(0,1,1,0) = type(7);
    new_synaptic_weights(0,1,1,1) = type(8);
    new_synaptic_weights(1,0,0,0) = type(9);
    new_synaptic_weights(1,0,0,1) = type(10);
    new_synaptic_weights(1,0,1,0) = type(11);
    new_synaptic_weights(1,0,1,1) = type(12);
    new_synaptic_weights(1,1,0,0) = type(13);
    new_synaptic_weights(1,1,0,1) = type(14);
    new_synaptic_weights(1,1,1,0) = type(15);
    new_synaptic_weights(1,1,1,1) = type(16);

    new_biases(0) = type(100);
    new_biases(1) = type(200);

    parameters(0) = type(100);
    parameters(1) = type(200);
    parameters(2) = type(1);
    parameters(3) = type(2);
    parameters(4) = type(3);
    parameters(5) = type(4);
    parameters(6) = type(5);
    parameters(7) = type(6);
    parameters(8) = type(7);
    parameters(9) = type(8);
    parameters(10) = type(9);
    parameters(11) = type(10);
    parameters(12) = type(11);
    parameters(13) = type(12);
    parameters(14) = type(13);
    parameters(15) = type(14);
    parameters(16) = type(15);
    parameters(17) = type(16);

    convolutional_layer.set_parameters(parameters, 0);

    const Tensor<type, 4> synaptic_weight = convolutional_layer.get_synaptic_weights();
    const Tensor<type, 1> biases = convolutional_layer.get_biases();

    assert_true(abs(biases(0) - new_biases(0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(biases(1) - new_biases(1)) < type(NUMERIC_LIMITS_MIN),LOG);

    assert_true(abs(synaptic_weight(0,0,0,0) - new_synaptic_weights(0,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,0,0,1) - new_synaptic_weights(0,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,0,1,0) - new_synaptic_weights(0,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,0,1,1) - new_synaptic_weights(0,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,1,0,0) - new_synaptic_weights(0,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,1,0,1) - new_synaptic_weights(0,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,1,1,0) - new_synaptic_weights(0,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(0,1,1,1) - new_synaptic_weights(0,1,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,0,0,0) - new_synaptic_weights(1,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,0,0,1) - new_synaptic_weights(1,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,0,1,0) - new_synaptic_weights(1,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,0,1,1) - new_synaptic_weights(1,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,1,0,0) - new_synaptic_weights(1,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,1,0,1) - new_synaptic_weights(1,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,1,1,0) - new_synaptic_weights(1,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(synaptic_weight(1,1,1,1) - new_synaptic_weights(1,1,1,1)) < type(NUMERIC_LIMITS_MIN), LOG);


//    assert_true(!convolutional_layer.is_empty() &&
//                convolutional_layer.get_parameters_number() == 18 &&
//                convolutional_layer.get_synaptic_weights() == new_synaptic_weights &&
//                convolutional_layer.get_biases() == new_biases, LOG);
*/}


void ConvolutionalLayerTest::test_calculate_combinations()
{
    cout << "test_calculate_combinations\n";

    const Index input_images = 1;
    const Index input_kernels = 3;

    const Index channels = 3;

    const Index rows_input = 5;
    const Index cols_input = 5;
    const Index rows_kernel = 3;
    const Index cols_kernel = 3;

    Tensor<type, 4> inputs(rows_input,cols_input,channels,input_images);
    Tensor<type, 4> kernels(rows_kernel,cols_kernel,channels,input_kernels);

    Tensor<type, 4> combinations((rows_input - rows_kernel) + 1,
                                 (cols_input - cols_kernel) + 1,
                                 input_kernels,
                                 input_images);

    Tensor<type, 1> biases(channels);

    inputs.setConstant(type(1.));
    kernels.setConstant(type(1./12.));

    biases(0) = type(0.);
    biases(1) = type(1.);
    biases(2) = type(2.);

    Tensor<Index, 1> new_inputs_dimension(4);
    Tensor<Index, 1> new_kernels_dimensions(4);

    new_inputs_dimension.setValues({rows_input, cols_input, channels,input_images});
    new_kernels_dimensions.setValues({rows_kernel, cols_kernel,channels,input_kernels});

    ConvolutionalLayer convolutional_layer(new_inputs_dimension, new_kernels_dimensions);

    convolutional_layer.set_biases(biases);
    convolutional_layer.set_synaptic_weights(kernels);

    convolutional_layer.calculate_convolutions(inputs, combinations);

    assert_true(abs(combinations(0, 0, 0, 0) - type(2.25)) < type(NUMERIC_LIMITS_MIN)&&
                abs(combinations(0, 0, 1, 0) - type(3.25)) < type(NUMERIC_LIMITS_MIN)&&
                abs(combinations(0, 0, 2, 0) - type(4.25)) < type(NUMERIC_LIMITS_MIN), LOG);

    inputs.resize(5, 5, 2, 2);
    kernels.resize(2, 2, 2, 2);
    combinations.resize(4, 4, 2, 2);
    biases.resize(2);

    inputs.chip(0, 3).setConstant(type(1.));
    inputs.chip(1, 3).setConstant(type(2.));
    kernels.chip(0, 3).setConstant(type(1./8.));
    kernels.chip(1, 3).setConstant(type(1./4.));

    biases(0) = type(0);
    biases(1) = type(1);

    convolutional_layer.set_biases(biases);
    convolutional_layer.set_synaptic_weights(kernels);
    convolutional_layer.calculate_convolutions(inputs, combinations);

    assert_true(abs(combinations(0, 0, 0, 0) - type(1.)) < type(NUMERIC_LIMITS_MIN)&&
                abs(combinations(0, 0, 1, 0) - type(3.)) < type(NUMERIC_LIMITS_MIN)&&
                abs(combinations(0, 0, 0, 1) - type(2.)) < type(NUMERIC_LIMITS_MIN)&&
                abs(combinations(0, 0, 1, 1) - type(5.)) < type(NUMERIC_LIMITS_MIN), LOG);
}

///@todo include this in pooling

void ConvolutionalLayerTest::test_calculate_average_pooling_outputs()
{
    cout << "test_calculate_max_pooling_outputs\n";

    //input_dims
    const Index input_images = 1;
    const Index channels = 1;

    const Index rows_input = 4;
    const Index cols_input = 4;

    //pooling dims
    const Index rows_polling = 2;
    const Index cols_polling = 2;

    //stride
    const Index rows_stride=1;
    const Index cols_stride=1;

    //output dims
    const Index output_rows_number = (rows_input - rows_polling)/rows_stride + 1;
    const Index output_cols_number = (cols_input - cols_polling)/cols_stride +1;

    Tensor<type, 4> inputs(rows_input, cols_input, channels, input_images);
    Tensor<type, 4> outputs(output_rows_number, output_cols_number, channels, input_images);

    inputs.setRandom();

    //pooling average

    Index col = 0;
    Index row = 0;

    for(int i=0; i<input_images; i++)
    {
        for(int c=0; c<channels; c++)
        {
            for(int k=0; k<output_cols_number; k++)
            {
                for(int l=0; l<output_rows_number; l++)
                {
                    float tmp_result = 0;

                    for(int m=0; m<cols_polling; m++)
                    {
                        col = m*cols_stride + k;

                        for(int n=0; n<rows_polling; n++)
                        {
                            row = n*rows_stride + l;

                            tmp_result += inputs(row,col,c,i);
                        }
                    }
                    outputs(l,k,c,i) = tmp_result/(cols_polling*rows_polling);
                }
            }
        }
    }
}


void ConvolutionalLayerTest::test_calculate_max_pooling_outputs()
{
    cout << "test_calculate_max_pooling_outputs\n";

    //input_dims
    const Index input_images = 1;
    const Index channels = 1;

    const Index rows_input = 4;
    const Index cols_input = 4;

    //pooling dims
    const Index rows_polling = 2;
    const Index cols_polling = 2;

    //stride
    const Index rows_stride=1;
    const Index cols_stride=1;

    //output dims
    const Index output_rows_number = (rows_input - rows_polling)/rows_stride + 1;
    const Index output_cols_number = (cols_input - cols_polling)/cols_stride +1;

    Tensor<type, 4> inputs(rows_input, cols_input, channels, input_images);
    Tensor<type, 4> outputs(output_rows_number, output_cols_number, channels, input_images);

    inputs.setRandom();

    //pooling average

    Index col = 0;
    Index row = 0;

    for(int i=0; i<input_images; i++)
    {
        for(int c=0; c<channels; c++)
        {
            for(int k=0; k<output_cols_number; k++)
            {
                for(int l=0; l<output_rows_number; l++)
                {
                    float tmp_result = 0;

                    float final_result = 0;

                    for(int m=0; m<cols_polling; m++)
                    {
                        col = m*cols_stride + k;

                        for(int n=0; n<rows_polling; n++)
                        {
                            row = n*rows_stride + l;

                            tmp_result = inputs(row,col,c,i);

                            if(tmp_result > final_result) final_result = tmp_result;
                        }
                    }
                    outputs(l,k,c,i) = final_result;
                }
            }
        }
    }
}




void ConvolutionalLayerTest::test_calculate_activations()
{
    cout << "test_calculate_activations\n";

    Tensor<type, 4> inputs;
    Tensor<type, 4> activations_4d;
    Tensor<type, 4> result;

    result.resize(2,2,2,2);
    inputs.resize(2,2,2,2);

    Tensor<Index, 1> new_inputs_dimensions(4);
    Tensor<Index, 1> new_kernels_dimensions(4);

    new_inputs_dimensions.setValues({2, 2, 2, 2});
    new_kernels_dimensions.setValues({2, 2, 2, 2});

    ConvolutionalLayer convolutional_layer(new_inputs_dimensions, new_kernels_dimensions);

    // Test

    inputs(0,0,0,0) = type(type(-1.111f));
    inputs(0,0,0,1) = type(type(-1.112));
    inputs(0,0,1,0) = type(type(-1.121));
    inputs(0,0,1,1) = type(-1.122f);
    inputs(0,1,0,0) = type(1.211f);
    inputs(0,1,0,1) = type(1.212f);
    inputs(0,1,1,0) = type(1.221f);
    inputs(0,1,1,1) = type(1.222f);
    inputs(1,0,0,0) = type(-2.111f);
    inputs(1,0,0,1) = type(-2.112f);
    inputs(1,0,1,0) = type(-2.121f);
    inputs(1,0,1,1) = type(-2.122f);
    inputs(1,1,0,0) = type(2.211f);
    inputs(1,1,0,1) = type(2.212f);
    inputs(1,1,1,0) = type(2.221f);
    inputs(1,1,1,1) = type(2.222f);

    activations_4d.resize(2,2,2,2);
    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::Threshold);
    convolutional_layer.calculate_activations(inputs, activations_4d);

    assert_true(activations_4d(0,0,0,0) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,0,1) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,1,0) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,1,1) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,1,0,0) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,1,0,1) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,1,1,0) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,1,1,1) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,0,0) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,0,1) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,1,0) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,1,1) - type(0) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,1,0,0) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,1,0,1) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,1,1,0) - type(1) < type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,1,1,1) - type(1) < type(NUMERIC_LIMITS_MIN), LOG);


    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::SymmetricThreshold);

    convolutional_layer.calculate_activations(inputs, activations_4d);

    //    assert_true(activations == result, LOG);

    assert_true(activations_4d(0,0,0,0) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,0,1) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,1,0) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,0,1,1) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(0,1,0,0) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,0,1) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,1,0) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,1,1) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,0,0,0) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,0,1) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,1,0) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,0,1,1) - type(-1)<type(NUMERIC_LIMITS_MIN) &&
                activations_4d(1,1,0,0) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,0,1) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,1,0) - type(1) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,1,1) - type(1) <type(NUMERIC_LIMITS_MIN), LOG);

    // Test

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::HyperbolicTangent);
    convolutional_layer.calculate_activations(inputs, activations_4d);

    assert_true(abs(activations_4d(0,0,0,0) - type(-0.804416f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,0,0,1) - type(-0.804768f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,0,1,0) - type(-0.807916f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,0,1,1) - type(-0.808263f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,1,0,0) - type(0.836979f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,1,0,1) - type(0.837278f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,1,1,0) - type(0.839949f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(0,1,1,1) - type(0.840243f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,0,0,0) - type(-0.971086f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,0,0,1) - type(-0.971143f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,0,1,0) - type(-0.971650f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,0,1,1) - type(-0.971706f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,1,0,0) - type(0.976265f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,1,0,1) - type(0.976312f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,1,1,0) - type(0.976729f)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_4d(1,1,1,1) - type(0.976775f)) < type(NUMERIC_LIMITS_MIN), LOG);

    // Test

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::RectifiedLinear);
    convolutional_layer.calculate_activations(inputs, activations_4d);

    assert_true(activations_4d(0,0,0,0) - type(0) <type(NUMERIC_LIMITS_MIN),LOG);

    assert_true(activations_4d(0,0,0,0) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,0,0,1) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,0,1,0) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,0,1,1) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,0,0) - type(1.211f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,0,1) - type(1.212f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,1,0) - type(1.221f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(0,1,1,1) - type(1.222f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,0,0,0) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,0,0,1) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,0,1,0) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,0,1,1) - type(0) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,0,0) - type(2.211f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,0,1) - type(2.212f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,1,0) - type(2.221f) <type(NUMERIC_LIMITS_MIN)&&
                activations_4d(1,1,1,1) - type(2.222f) <type(NUMERIC_LIMITS_MIN), LOG);

}


void ConvolutionalLayerTest::test_calculate_activations_derivatives()
{
    cout << "test_calculate_activations_derivatives\n";

    Tensor<type, 4> inputs;
    Tensor<type, 4> activations_derivatives;
    Tensor<type, 4> activations;
    Tensor<type, 4> result;

    activations.resize(2, 2, 2, 2);
    activations_derivatives.resize(2, 2, 2, 2);

    ConvolutionalLayer convolutional_layer;

    // Test

    inputs.resize(2, 2, 2, 2);
    inputs(0,0,0,0) = type(-1.111f);
    inputs(0,0,0,1) = type(-1.112);
    inputs(0,0,1,0) = type(-1.121);
    inputs(0,0,1,1) = type(-1.122f);
    inputs(0,1,0,0) = type(1.211f);
    inputs(0,1,0,1) = type(1.212f);
    inputs(0,1,1,0) = type(1.221f);
    inputs(0,1,1,1) = type(1.222f);
    inputs(1,0,0,0) = type(-2.111f);
    inputs(1,0,0,1) = type(-2.112f);
    inputs(1,0,1,0) = type(-2.121f);
    inputs(1,0,1,1) = type(-2.122f);
    inputs(1,1,0,0) = type(2.211f);
    inputs(1,1,0,1) = type(2.212f);
    inputs(1,1,1,0) = type(2.221f);
    inputs(1,1,1,1) = type(2.222f);

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::Threshold);

    convolutional_layer.calculate_activations_derivatives(inputs,
                                                          activations,
                                                          activations_derivatives);

    result = activations.constant(type(0));

    assert_true((activations_derivatives(0, 0, 0, 0) - result(0, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 0) - result(0, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 0) - result(1, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 0) - result(1, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 0) - result(0, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 0) - result(0, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 0) - result(1, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 0) - result(1, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 0, 1) - result(0, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 1) - result(0, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 1) - result(1, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 1) - result(1, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 1) - result(0, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 1) - result(0, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 1) - result(1, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 1) - result(1, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN), LOG);

    inputs(0,0,0,0) = type(-1.111f);
    inputs(0,0,0,1) = type(-1.112);
    inputs(0,0,1,0) = type(-1.121);
    inputs(0,0,1,1) = type(-1.122f);
    inputs(0,1,0,0) = type(1.211f);
    inputs(0,1,0,1) = type(1.212f);
    inputs(0,1,1,0) = type(1.221f);
    inputs(0,1,1,1) = type(1.222f);
    inputs(1,0,0,0) = type(-2.111f);
    inputs(1,0,0,1) = type(-2.112f);
    inputs(1,0,1,0) = type(-2.121f);
    inputs(1,0,1,1) = type(-2.122f);
    inputs(1,1,0,0) = type(2.211f);
    inputs(1,1,0,1) = type(2.212f);
    inputs(1,1,1,0) = type(2.221f);
    inputs(1,1,1,1) = type(2.222f);

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::SymmetricThreshold);

    convolutional_layer.calculate_activations_derivatives(inputs,
                                                          activations,
                                                          activations_derivatives);

    result = activations.constant(type(0));

    assert_true((activations_derivatives(0, 0, 0, 0) - result(0, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 0) - result(0, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 0) - result(1, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 0) - result(1, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 0) - result(0, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 0) - result(0, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 0) - result(1, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 0) - result(1, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 0, 1) - result(0, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 1) - result(0, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 1) - result(1, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 1) - result(1, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 1) - result(0, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 1) - result(0, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 1) - result(1, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 1) - result(1, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN), LOG);

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::HyperbolicTangent);

    convolutional_layer.calculate_activations_derivatives(inputs,
                                                          activations,
                                                          activations_derivatives);

    result(0,0,0,0) = type(0.352916f);
    result(0,0,0,1) = type(0.352348f);
    result(0,0,1,0) = type(0.347271f);
    result(0,0,1,1) = type(0.346710f);
    result(0,1,0,0) = type(0.299466f);
    result(0,1,0,1) = type(0.298965f);
    result(0,1,1,0) = type(0.294486f);
    result(0,1,1,1) = type(0.293991f);
    result(1,0,0,0) = type(0.056993f);
    result(1,0,0,1) = type(0.056882f);
    result(1,0,1,0) = type(0.055896f);
    result(1,0,1,1) = type(0.055788f);
    result(1,1,0,0) = type(0.046907f);
    result(1,1,0,1) = type(0.046816f);
    result(1,1,1,0) = type(0.046000f);
    result(1,1,1,1) = type(0.045910f);

    assert_true(abs(activations_derivatives(0,0,0,0) - result(0,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,0,1) - result(0,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,1,0) - result(0,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,1,1) - result(0,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,0,0) - result(0,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,0,1) - result(0,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,1,0) - result(0,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,1,1) - result(0,1,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,0,0) - result(1,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,0,1) - result(1,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,1,0) - result(1,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,1,1) - result(1,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,0,0) - result(1,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,0,1) - result(1,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,1,0) - result(1,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,1,1) - result(1,1,1,1)) < type(NUMERIC_LIMITS_MIN), LOG);

    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::RectifiedLinear);

    convolutional_layer.calculate_activations_derivatives(inputs,
                                                          activations,
                                                          activations_derivatives);

    result(0,0,0,0) = type(0);
    result(0,0,0,1) = type(0);
    result(0,0,1,0) = type(0);
    result(0,0,1,1) = type(0);
    result(0,1,0,0) = type(1);
    result(0,1,0,1) = type(1);
    result(0,1,1,0) = type(1);
    result(0,1,1,1) = type(1);
    result(1,0,0,0) = type(0);
    result(1,0,0,1) = type(0);
    result(1,0,1,0) = type(0);
    result(1,0,1,1) = type(0);
    result(1,1,0,0) = type(1);
    result(1,1,0,1) = type(1);
    result(1,1,1,0) = type(1);
    result(1,1,1,1) = type(1);

    assert_true((activations_derivatives(0, 0, 0, 0) - result(0, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 0) - result(0, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 0) - result(1, 0, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 0) - result(1, 1, 0, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 0) - result(0, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 0) - result(0, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 0) - result(1, 0, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 0) - result(1, 1, 1, 0)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 0, 1) - result(0, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 0, 1) - result(0, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 0, 1) - result(1, 0, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 0, 1) - result(1, 1, 0, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 0, 1, 1) - result(0, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(0, 1, 1, 1) - result(0, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 0, 1, 1) - result(1, 0, 1, 1)) <= type(NUMERIC_LIMITS_MIN) &&
                (activations_derivatives(1, 1, 1, 1) - result(1, 1, 1, 1)) <= type(NUMERIC_LIMITS_MIN), LOG);


    convolutional_layer.set_activation_function(opennn::ConvolutionalLayer::ActivationFunction::SoftPlus);
    convolutional_layer.calculate_activations_derivatives(inputs,
                                                          activations,
                                                          activations_derivatives);

    result(0,0,0,0) = type(0.247685f);
    result(0,0,0,1) = type(0.247498f);
    result(0,0,1,0) = type(0.245826f);
    result(0,0,1,1) = type(0.245640f);
    result(0,1,0,0) = type(0.770476f);
    result(0,1,0,1) = type(0.770653f);
    result(0,1,1,0) = type(0.772239f);
    result(0,1,1,1) = type(0.772415f);
    result(1,0,0,0) = type(0.108032f);
    result(1,0,0,1) = type(0.107936f);
    result(1,0,1,0) = type(0.107072f);
    result(1,0,1,1) = type(0.106977f);
    result(1,1,0,0) = type(0.901233f);
    result(1,1,0,1) = type(0.901322f);
    result(1,1,1,0) = type(0.902120f);
    result(1,1,1,1) = type(0.902208f);

    assert_true(abs(activations_derivatives(0,0,0,0) - result(0,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,0,1) - result(0,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,1,0) - result(0,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,0,1,1) - result(0,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,0,0) - result(0,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,0,1) - result(0,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,1,0) - result(0,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(0,1,1,1) - result(0,1,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,0,0) - result(1,0,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,0,1) - result(1,0,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,1,0) - result(1,0,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,0,1,1) - result(1,0,1,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,0,0) - result(1,1,0,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,0,1) - result(1,1,0,1)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,1,0) - result(1,1,1,0)) < type(NUMERIC_LIMITS_MIN) &&
                abs(activations_derivatives(1,1,1,1) - result(1,1,1,1)) < type(NUMERIC_LIMITS_MIN), LOG);
}


void ConvolutionalLayerTest::test_forward_propagate()
{
    cout << "test_forward_propagate\n";

    const Index input_images = 2;
    const Index input_kernels = 3;

    const Index channels = 3;

    const Index rows_input = 4;
    const Index cols_input = 4;
    const Index rows_kernel = 3;
    const Index cols_kernel = 3;

    Tensor<type,4> inputs(rows_input, cols_input, channels, input_images);
    Tensor<type,4> kernel(rows_kernel, cols_kernel, channels, input_kernels);
    Tensor<type,1> bias(input_kernels);
    inputs.setConstant(1.);
    bias.setValues({0,1,2});

    inputs.chip(0,3).chip(0,2).setConstant(2.);
    inputs.chip(0,3).chip(1,2).setConstant(3.);
    inputs.chip(0,3).chip(2,2).setConstant(4.);

    kernel.chip(0,3).setConstant(type(1./3.));
    kernel.chip(1,3).setConstant(type(1./9.));
    kernel.chip(2,3).setConstant(type(1./27.));

    convolutional_layer.set(inputs, kernel, bias);

    forward_propagation.set(input_images, &convolutional_layer);

    convolutional_layer.set_activation_function(ConvolutionalLayer::ActivationFunction::HyperbolicTangent);

    convolutional_layer.forward_propagate(inputs, &forward_propagation);

    assert_true(forward_propagation.activations.dimension(0) == convolutional_layer.get_outputs_dimensions()(0)&&
                forward_propagation.activations.dimension(1) == convolutional_layer.get_outputs_dimensions()(1)&&
                forward_propagation.activations.dimension(2) == convolutional_layer.get_outputs_dimensions()(2)&&
                forward_propagation.activations.dimension(3) == convolutional_layer.get_outputs_dimensions()(3), LOG);

    assert_true(forward_propagation.activations_derivatives.dimension(0) == convolutional_layer.get_outputs_dimensions()(0)&&
                forward_propagation.activations_derivatives.dimension(1) == convolutional_layer.get_outputs_dimensions()(1)&&
                forward_propagation.activations_derivatives.dimension(2) == convolutional_layer.get_outputs_dimensions()(2)&&
                forward_propagation.activations_derivatives.dimension(3) == convolutional_layer.get_outputs_dimensions()(3), LOG);


    assert_true(abs(forward_propagation.activations(0, 0, 0, 0) - type(tanh(27.))) < type(NUMERIC_LIMITS_MIN) &&
                abs(forward_propagation.activations(0, 0, 1, 0) - type(tanh(10.))) < type(NUMERIC_LIMITS_MIN) &&
                abs(forward_propagation.activations(0, 0, 2, 0) - type(tanh(5.))) < type(NUMERIC_LIMITS_MIN) &&
                abs(forward_propagation.activations(0, 0, 0, 1) - type(tanh(9.))) < type(NUMERIC_LIMITS_MIN) &&
                abs(forward_propagation.activations(0, 0, 1, 1) - type(tanh(4.))) < type(NUMERIC_LIMITS_MIN) &&
                abs(forward_propagation.activations(0, 0, 2, 1) - type(tanh(3.))) < type(NUMERIC_LIMITS_MIN), LOG);

    assert_true(forward_propagation.combinations(0, 0, 0, 0) - type(27) < type(0.00001) &&
                forward_propagation.activations(0, 0, 0, 0) - type(1.) < type(0.00001) &&
                type(forward_propagation.activations_derivatives(0, 0, 0, 0)) - type(0.)< type(0.00001), LOG);
}


void ConvolutionalLayerTest::test_insert_padding()
{
    cout << "test_insert_padding\n";

    const Index input_images = 2;
    const Index input_kernels = 3;

    const Index channels = 3;

    const Index rows_input = 4;
    const Index cols_input = 4;
    const Index rows_kernel = 3;
    const Index cols_kernel = 3;

    Tensor<type,4> inputs(rows_input, cols_input, channels, input_images);
    Tensor<type,4> kernels(rows_kernel, cols_kernel, channels, input_kernels);
    Tensor<type,4> padded(rows_input, cols_input, channels, input_images);

    inputs.setConstant(type(1));

    Tensor<Index, 1> inputs_dimensions(4);
    inputs_dimensions.setValues({rows_input, cols_input, channels, input_images});

    Tensor<Index, 1> kernels_dimensions(4);
    kernels_dimensions.setValues({rows_kernel, cols_kernel, channels, input_kernels});

    ConvolutionalLayer convolutional_layer(inputs_dimensions, kernels_dimensions);

    convolutional_layer.set_convolution_type(opennn::ConvolutionalLayer::ConvolutionType::Same);
    convolutional_layer.set(inputs_dimensions, kernels_dimensions);

    convolutional_layer.insert_padding(inputs, padded);

    assert_true(padded.dimension(0) == 6 &&
                padded.dimension(1) == 6,LOG);

    assert_true((padded(0, 0, 0, 0) - type(0)) < type(NUMERIC_LIMITS_MIN) &&
                (padded(0, 1, 0, 0) - type(0)) < type(NUMERIC_LIMITS_MIN) &&
                (padded(0, 2, 0, 0) - type(0)) < type(NUMERIC_LIMITS_MIN), LOG);
}


void ConvolutionalLayerTest::test_calculate_hidden_delta_perceptron_test()
{
    cout<< "calculate_hidden_delta_perceptron_test"<<endl;

    // Current layer's values

    const Index images_number = 2;
    const Index kernels_number = 2;
    const Index output_rows_number = 4;
    const Index output_columns_number = 4;


    // Next layer's values

    const Index neurons_perceptron = 3;

    PerceptronLayer perceptronlayer(kernels_number*output_rows_number*output_columns_number,
                                    neurons_perceptron, PerceptronLayer::ActivationFunction::Linear);

    convolutional_layer.set(Tensor<type, 4>(5,5,3,1), Tensor<type, 4>(2, 2, 3, kernels_number), Tensor<type, 1>());

    PerceptronLayerForwardPropagation perceptron_layer_forward_propagate(images_number, &perceptronlayer);
    PerceptronLayerBackPropagation perceptron_layer_backpropagate(images_number, &perceptronlayer);
    ConvolutionalLayerBackPropagation convolutional_layer_backpropagate(images_number, &convolutional_layer);

    // initialize

    Tensor<float,2> synaptic_weights_perceptron(kernels_number * output_rows_number * output_columns_number,
                                                neurons_perceptron);

    for(int i=0; i<kernels_number * output_rows_number * output_columns_number*neurons_perceptron; i++)
    {
        Index neuron_value = i / (kernels_number * output_rows_number * output_columns_number);

        *(synaptic_weights_perceptron.data() + i) = 1.0 * neuron_value;
    }
/*
    perceptron_layer_backpropagate.deltas.setValues({{1,1,1},
                                                    {2,2,2}});

    perceptronlayer.set_synaptic_weights(synaptic_weights_perceptron);


    convolutional_layer.calculate_hidden_delta_perceptron(&perceptron_layer_forward_propagate,
                                                          &perceptron_layer_backpropagate,
                                                          &convolutional_layer_backpropagate);

    cout << convolutional_layer_backpropagate.deltas << endl;
*/
}



void ConvolutionalLayerTest::test_memcpy_approach()
{

    const int images_number = 1;
    const int kernel_number = 1;

    const int channel = 3;

    const int rows_input = 4;
    const int cols_input = 4;

    const int kernel_rows = 2;
    const int kernel_cols = 2;

    Tensor<type, 4> input(rows_input, cols_input, channel, images_number);
    Tensor<type, 4> kernel(kernel_rows, kernel_cols, channel, kernel_number);
    Tensor<type, 4> result((rows_input-kernel_rows)+1,
                           (cols_input-kernel_cols)+1,
                            kernel_number,
                            images_number);

    Tensor<type, 3> tmp_result((rows_input-kernel_rows)+1,
                               (cols_input-kernel_cols)+1,
                               1);

    const Index output_size_rows_cols = ((rows_input-kernel_rows)+1)*((cols_input-kernel_cols)+1);

    float* ptr_result = (float*) malloc(static_cast<size_t>(output_size_rows_cols*kernel_number*images_number*sizeof(type)));

    input.setConstant(1.0);

    input.chip(0,2).setConstant(1.);
    input.chip(1,2).setConstant(2.);
    input.chip(2,2).setConstant(3.);

    kernel.setConstant(type(1./12.));
    kernel.chip(1,3).setConstant(type(1./6.));

    time_t beginning_time;
    time_t current_time;
    time(&beginning_time);
    type elapsed_time = type(0);

    const Eigen::array<ptrdiff_t, 3> dims = {0, 1, 2};

    #pragma omp parallel for
    for(int i =0; i<images_number ;i++)
    {
        const Index next_image = input.dimension(0)*input.dimension(1)*input.dimension(2);

        const TensorMap<Tensor<type, 3>> single_image(input.data()+i*next_image, input.dimension(0), input.dimension(1), input.dimension(2));

        for(int j =0; j<kernel_number; j++)
        {
            const Index next_kernel = kernel.dimension(0)*kernel.dimension(1)*kernel.dimension(2);

            const TensorMap<Tensor<type, 3>> single_kernel(kernel.data()+j*next_kernel , kernel.dimension(0), kernel.dimension(1), kernel.dimension(2));

            Tensor<type, 3> tmp_result = single_image.convolve(single_kernel, dims);

            memcpy(result.data() +j*output_size_rows_cols +i*output_size_rows_cols*kernel_number,
                   tmp_result.data(), output_size_rows_cols*sizeof(type));
         }
    }
}

void ConvolutionalLayerTest::run_test_case()
{
   cout << "Running convolutional layer test case...\n";

   // Constructor and destructor

   test_constructor();
   test_destructor();

   // Set methods

   test_set();
   test_set_parameters();

   // Convolutions

   test_eigen_convolution();
   test_eigen_convolution_3d();
   test_read_bmp();

   // Combinations

   test_calculate_combinations();
   test_calculate_average_pooling_outputs();
   test_calculate_max_pooling_outputs();

   // Activation

   test_calculate_activations();
   test_calculate_activations_derivatives();

   // Outputs

//   test_calculate_outputs();

   // Padding

   test_insert_padding();

   // Forward propagate

   test_forward_propagate();

   // Back_propagate

   test_calculate_hidden_delta_perceptron_test();

   //Utils
   test_memcpy_approach();

   cout << "End of convolutional layer test case.\n\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2021 Artificial Intelligence Techniques, SL.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
;
